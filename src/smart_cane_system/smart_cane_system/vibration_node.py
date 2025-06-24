#!/usr/bin/env python3

"""
Enhanced Vibration Node with VERY distinct patterns:
- SLOW: Long, gentle pulses for far objects (2-3m) 
- MEDIUM: Moderate pulses for medium distance (1-2m)
- FAST: Rapid, urgent pulses for close objects (<1m)
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
        
        self.get_logger().info('🔥 Enhanced Vibration Node with Distinct Patterns initialized')
        self.get_logger().info('   SLOW: Long gentle pulses (far objects)')
        self.get_logger().info('   MEDIUM: Moderate pulses (medium distance)')  
        self.get_logger().info('   FAST: Rapid urgent pulses (close danger!)')

    def vibration_callback(self, msg):
        self.get_logger().info(f'📳 Vibration command: {msg.data}')
        
        if msg.data == 'Fast':
            self.vib_fast()
        elif msg.data == 'Medium':
            self.vib_medium()
        elif msg.data == 'Slow':
            self.vib_slow()

    def vib_slow(self):
        """SLOW: Very gentle, long pulses for far objects (2-3m)"""
        # Long, relaxed pulses - like a slow heartbeat
        self.get_logger().info('💙 SLOW vibration: Far object detected')
        threading.Thread(target=self.vibrate_pattern, args=(0.8, 1.2, 3)).start()
        # 0.8s ON, 1.2s OFF, only 3 cycles = very relaxed

    def vib_medium(self):
        """MEDIUM: Moderate pulses for medium distance (1-2m)"""
        # Moderate pace - noticeable but not urgent
        self.get_logger().info('🟡 MEDIUM vibration: Medium distance object')
        threading.Thread(target=self.vibrate_pattern, args=(0.3, 0.4, 5)).start()
        # 0.3s ON, 0.4s OFF, 5 cycles = moderate rhythm

    def vib_fast(self):
        """FAST: Rapid urgent pulses for close objects (<1m)"""
        # Rapid, urgent pulses - immediate danger alert!
        self.get_logger().info('🔴 FAST vibration: CLOSE OBJECT - DANGER!')
        threading.Thread(target=self.vibrate_pattern, args=(0.1, 0.1, 15)).start()
        # 0.1s ON, 0.1s OFF, 15 cycles = very urgent and rapid

    def vibrate_pattern(self, on_time, off_time, cycles):
        """Execute vibration pattern"""
        for i in range(cycles):
            self.motor.on()
            time.sleep(on_time)
            self.motor.off()
            time.sleep(off_time)
        
        # Brief pause before allowing next pattern
        time.sleep(0.5)

    def destroy_node(self):
        self.motor.off()  # Turn off motor before cleanup
        super().destroy_node()

def main(args=None):
    # Initialize ROS2
    rclpy.init(args=args)
    # Create your node
    node = Vibration()
    try:
        # Spin the node (keep it running)
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('🛑 Enhanced vibration node stopped')
    finally:
        # Cleanup when done
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()