#!/usr/bin/env python3

"""
create the node
configure the pins  
create the publisher
create a callback when the distance arrives
"""

# All the imports
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32
from gpiozero import DistanceSensor
import time
import statistics

class Ultrasonic(Node):
    def __init__(self):
        super().__init__('ultrasonic_node')
        
        # Configure the pins using gpiozero (Pi 5 compatible)
        try:
            # Configure with explicit max_distance (default is only 1m!)
            self.sensor = DistanceSensor(echo=24, trigger=16, max_distance=4)
            self.get_logger().info('Ultrasonic sensor pins configured (max 4m range)')
        except Exception as e:
            self.get_logger().error(f'Failed to configure sensor: {e}')
            return

        # Simple moving average filter for stability
        self.reading_buffer = []
        self.buffer_size = 3  # Smaller buffer for faster response
        
        # Publisher Structure
        self.distance_publisher = self.create_publisher(
            Float32,
            '/distance',
            10
        )

        # Timer structure
        self.timer = self.create_timer(
            0.2,  # 200ms = 5Hz (good balance of speed vs accuracy)
            self.timer_callback
        )
        
        self.get_logger().info('Ultrasonic Node initialized')

    def timer_callback(self):
        """Callback when the distance measurement timer triggers"""
        try:
            # Get distance using gpiozero
            raw_distance = self.sensor.distance  # Returns distance in meters
            
            # Simple validation - accept all reasonable readings
            if 0.02 <= raw_distance <= 4.0:  # Valid range: 2cm to 4m
                
                # Add to moving average buffer
                self.reading_buffer.append(raw_distance)
                if len(self.reading_buffer) > self.buffer_size:
                    self.reading_buffer.pop(0)  # Remove oldest reading
                
                # Calculate simple moving average
                if len(self.reading_buffer) >= 2:  # Need at least 2 readings
                    # Use average for stability but keep responsiveness
                    filtered_distance = statistics.mean(self.reading_buffer)
                else:
                    filtered_distance = raw_distance
                
                # Publish the filtered reading
                distance_msg = Float32()
                distance_msg.data = filtered_distance
                self.distance_publisher.publish(distance_msg)
                
                # Log only significant changes to reduce spam
                if not hasattr(self, 'last_logged_distance') or abs(filtered_distance - self.last_logged_distance) > 0.1:
                    self.get_logger().info(f'Distance: {filtered_distance:.2f}m')
                    self.last_logged_distance = filtered_distance
                    
            else:
                # Invalid reading - skip this measurement
                self.get_logger().warn(f'Invalid distance reading: {raw_distance:.3f}m')
                
        except Exception as e:
            self.get_logger().error(f'Sensor error: {e}')

def main(args=None):
    # Initialize ROS2
    rclpy.init(args=args)
    # Create your node
    node = Ultrasonic()
    try:
        # Spin the node (keep it running)
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Ultrasonic node stopped by user')
    finally:
        # Cleanup when done
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()