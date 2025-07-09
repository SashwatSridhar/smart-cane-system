#!/usr/bin/env python3
"""
Enhanced Vibration Node optimized for 2.5m ultrasonic sensor range:
- SLOW: Gentle pulses for far detection (2.0-2.5m)
- MEDIUM: Moderate pulses for medium distance (1.0-2.0m)  
- FAST: Rapid, urgent pulses for close objects (<1.0m)
"""
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from gpiozero import OutputDevice
import time
import threading

class Vibration(Node):
    def __init__(self):
        super().__init__('vibration_node')
        
        # GPIO Setup with gpiozero (Pi 5 + Ubuntu compatible)
        self.motor = OutputDevice(23)  # Pin 16 = GPIO 23
        self.motor.off()  # Start with motor off
        
        # Subscriber
        self.vibration_alert_listener = self.create_subscription(
            String,
            '/obstacle_alert',
            self.vibration_callback,
            10
        )
        
        self.get_logger().info('🔥 Enhanced Vibration Node (2.5m range optimized)')
        self.get_logger().info('💙 SLOW: Gentle pulses (2.0-2.5m range)')
        self.get_logger().info('🟡 MEDIUM: Moderate pulses (1.0-2.0m range)')
        self.get_logger().info('🔴 FAST: Urgent pulses (<1.0m - DANGER!)')

    def vibration_callback(self, msg):
        self.get_logger().info(f'📳 Vibration command received: {msg.data}')
        
        if msg.data == 'Fast':
            self.vib_fast()
        elif msg.data == 'Medium':
            self.vib_medium()
        elif msg.data == 'Slow':
            self.vib_slow()
        else:
            self.get_logger().warn(f'Unknown vibration command: {msg.data}')

    def vib_slow(self):
        """SLOW: Gentle, long pulses for far detection (2.0-2.5m)"""
        # Relaxed pulses - object detected but not immediate concern
        self.get_logger().info('💙 SLOW vibration: Far object (2.0-2.5m)')
        threading.Thread(target=self.vibrate_pattern, args=(0.6, 1.0, 4)).start()
        # 0.6s ON, 1.0s OFF, 4 cycles = gentle notification

    def vib_medium(self):
        """MEDIUM: Moderate pulses for medium distance (1.0-2.0m)"""
        # Noticeable but measured pace - proceed with caution
        self.get_logger().info('🟡 MEDIUM vibration: Medium distance (1.0-2.0m)')
        threading.Thread(target=self.vibrate_pattern, args=(0.3, 0.4, 6)).start()
        # 0.3s ON, 0.4s OFF, 6 cycles = clear warning

    def vib_fast(self):
        """FAST: Rapid urgent pulses for close objects (<1.0m)"""
        # Immediate danger alert - stop or change direction!
        self.get_logger().info('🔴 FAST vibration: CLOSE OBJECT (<1.0m) - DANGER!')
        threading.Thread(target=self.vibrate_pattern, args=(0.1, 0.1, 12)).start()
        # 0.1s ON, 0.1s OFF, 12 cycles = urgent warning

    def vibrate_pattern(self, on_time, off_time, cycles):
        """Execute vibration pattern"""
        start_time = time.time()
        
        for i in range(cycles):
            self.motor.on()
            time.sleep(on_time)
            self.motor.off()
            time.sleep(off_time)
        
        total_time = time.time() - start_time
        self.get_logger().debug(f'Vibration pattern completed in {total_time:.1f}s')
        
        # Brief pause before allowing next pattern
        time.sleep(0.3)

    def destroy_node(self):
        self.motor.off()  # Turn off motor before cleanup
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = Vibration()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('🛑 Enhanced vibration node stopped')
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()