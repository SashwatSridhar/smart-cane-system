#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32
from gpiozero import DistanceSensor
import time
import statistics

class Ultrasonic(Node):
    def __init__(self):
        super().__init__('ultrasonic_node')
        
        # Simple configuration (works without pigpio)
        try:
            self.sensor = DistanceSensor(
                echo=24, 
                trigger=18, 
                max_distance=4,
                threshold_distance=0.04,
                partial=False
            )
            self.get_logger().info('✅ HC-SR04+ configured (using default GPIO)')
        except Exception as e:
            self.get_logger().error(f'❌ Failed to configure sensor: {e}')
            return

        # Smart cane optimized settings
        self.reading_buffer = []
        self.buffer_size = 3
        self.consecutive_failures = 0
        self.max_consecutive_failures = 5
        
        # Stats
        self.total_readings = 0
        self.successful_readings = 0

        # Publisher
        self.distance_publisher = self.create_publisher(Float32, '/distance', 10)

        # Optimal timer for your setup (based on your test results)
        self.timer = self.create_timer(0.15, self.timer_callback)  # 6.7Hz

        self.get_logger().info('Smart Cane Ultrasonic ready! (No pigpio needed)')

    def timer_callback(self):
        """Smart cane navigation optimized"""
        self.total_readings += 1
        
        try:
            raw_distance = self.sensor.distance
            
            # Accept all reasonable readings (smart cane needs responsiveness)
            if 0.02 <= raw_distance <= 4.0:
                
                # Simple but effective filtering
                self.reading_buffer.append(raw_distance)
                if len(self.reading_buffer) > self.buffer_size:
                    self.reading_buffer.pop(0)
                
                # Quick averaging for responsiveness
                if len(self.reading_buffer) >= 2:
                    filtered_distance = statistics.mean(self.reading_buffer)
                else:
                    filtered_distance = raw_distance
                
                # Publish for navigation
                distance_msg = Float32()
                distance_msg.data = filtered_distance
                self.distance_publisher.publish(distance_msg)
                
                self.successful_readings += 1
                self.consecutive_failures = 0
                
                # Log navigation-relevant distances only
                if filtered_distance <= 3.0:
                    category = self.get_navigation_alert(filtered_distance)
                    self.get_logger().info(f'{category}: {filtered_distance:.2f}m')
                
                # Stats every 30 readings (less spam)
                if self.total_readings % 30 == 0:
                    success_rate = (self.successful_readings / self.total_readings) * 100
                    self.get_logger().info(f'📊 Success rate: {success_rate:.1f}%')
                    
            else:
                self.consecutive_failures += 1
                
        except Exception as e:
            self.consecutive_failures += 1
            if self.consecutive_failures <= 2:
                self.get_logger().warn(f'Reading error: {e}')
        
        # Sensor health check
        if self.consecutive_failures >= self.max_consecutive_failures:
            self.get_logger().error('🚨 Check sensor connections!')
            self.consecutive_failures = 0

    def get_navigation_alert(self, distance):
        """Smart cane distance categories"""
        if distance <= 0.5:
            return "🚨 IMMEDIATE"
        elif distance <= 1.0:
            return "⚠️  CLOSE"
        elif distance <= 2.0:
            return "📍 MEDIUM"
        else:
            return "👁️  FAR"

def main(args=None):
    rclpy.init(args=args)
    node = Ultrasonic()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Ultrasonic node stopped')
    finally:
        if hasattr(node, 'total_readings') and node.total_readings > 0:
            success_rate = (node.successful_readings / node.total_readings) * 100
            node.get_logger().info(f'Final success rate: {success_rate:.1f}%')
        
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()