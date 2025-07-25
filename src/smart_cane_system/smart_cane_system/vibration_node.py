#!/usr/bin/env python3
"""
Enhanced Vibration Node optimized for 2.4m ultrasonic sensor range:
- SLOW: Gentle pulses for far detection (2.0-2.4m)
- MEDIUM: Moderate pulses for medium distance (1.0-2.0m)
- FAST: Rapid, urgent pulses for close objects (<1.0m)
- STOP: Immediately stop all vibration
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
        
        # 🔧 ADD THREAD MANAGEMENT:
        self.vibration_thread = None
        self.stop_vibration = False
        self.thread_lock = threading.Lock()
        
        # Subscriber
        self.vibration_alert_listener = self.create_subscription(
            String,
            '/obstacle_alert',
            self.vibration_callback,
            10
        )
        
        self.get_logger().info('Enhanced Vibration Node (2.4m range optimized)')
        self.get_logger().info('SLOW: Gentle pulses (2.0-2.4m range)')
        self.get_logger().info('MEDIUM: Moderate pulses (1.0-2.0m range)')
        self.get_logger().info('FAST: Urgent pulses (<1.0m - DANGER!)')
        self.get_logger().info('STOP: Immediate vibration stop')

    def vibration_callback(self, msg):
        self.get_logger().info(f'Vibration command received: {msg.data}')
        
        with self.thread_lock:
            # STOP any ongoing vibration first
            self.stop_current_vibration()
            
            # Start new vibration
            if msg.data == 'Fast':
                self.vib_fast()
            elif msg.data == 'Medium':
                self.vib_medium()
            elif msg.data == 'Slow':
                self.vib_slow()
            elif msg.data == 'Stop':
                self.vib_stop()
            else:
                self.get_logger().warn(f'Unknown vibration command: {msg.data}')

    def stop_current_vibration(self):
        """Stop any currently running vibration"""
        self.stop_vibration = True
        if self.vibration_thread and self.vibration_thread.is_alive():
            self.vibration_thread.join(timeout=0.5)  # Wait briefly for thread to stop
        self.motor.off()
        self.stop_vibration = False

    def vib_stop(self):
        """STOP: Turn off vibration immediately"""
        self.stop_current_vibration()
        self.get_logger().info('STOP: Vibration stopped')

    def vib_slow(self):
        """SLOW: Gentle, long pulses for far detection (2.0-2.4m)"""
        self.get_logger().info('SLOW vibration: Far object (2.0-2.4m)')
        self.vibration_thread = threading.Thread(target=self.vibrate_pattern, args=(0.6, 1.0, 4))
        self.vibration_thread.start()

    def vib_medium(self):
        """MEDIUM: Moderate pulses for medium distance (1.0-2.0m)"""
        self.get_logger().info('MEDIUM vibration: Medium distance (1.0-2.0m)')
        self.vibration_thread = threading.Thread(target=self.vibrate_pattern, args=(0.3, 0.4, 6))
        self.vibration_thread.start()

    def vib_fast(self):
        """FAST: Rapid urgent pulses for close objects (<1.0m)"""
        self.get_logger().info('FAST vibration: CLOSE OBJECT (<1.0m) - DANGER!')
        self.vibration_thread = threading.Thread(target=self.vibrate_pattern, args=(0.1, 0.1, 12))
        self.vibration_thread.start()

    def vibrate_pattern(self, on_time, off_time, cycles):
        """Execute vibration pattern with interruption capability"""
        start_time = time.time()
        
        for i in range(cycles):
            #Check if we should stop
            if self.stop_vibration:
                break
                
            self.motor.on()
            time.sleep(on_time)
            
            #Check again before turning off
            if self.stop_vibration:
                break
                
            self.motor.off()
            time.sleep(off_time)
        
        # Ensure motor is off when pattern ends
        self.motor.off()
        
        total_time = time.time() - start_time
        self.get_logger().debug(f'Vibration pattern completed in {total_time:.1f}s')

    def destroy_node(self):
        self.stop_current_vibration()  # Stop vibration before cleanup
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = Vibration()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Enhanced vibration node stopped')
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()