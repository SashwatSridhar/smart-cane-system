#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import subprocess
import threading
import re

"""
Musical Tone Speaker - Uses simple beeps instead of speech
Much more reliable through Bluetooth than TTS!
"""

class Speaker(Node):
    def __init__(self):
        super().__init__('speaker_node')
        
        # Test if beep command works
        try:
            subprocess.run(['beep', '-f', '800', '-l', '200'], 
                         check=True, capture_output=True, timeout=2)
            self.beep_available = True
            self.get_logger().info('🎵 Musical Tone Speaker ready!')
        except:
            # Fallback to speaker-test
            self.beep_available = False
            self.get_logger().info('🔊 Using system speaker tones')

        # Subscriber
        self.obstacle_fusion_listener = self.create_subscription(
            String,
            '/audio_command',
            self.speaker,
            10
        )

    def speaker(self, msg):
        """Convert speech to musical tones"""
        threading.Thread(target=self.play_tones, args=(msg.data,)).start()

    def parse_distance(self, message):
        """Extract distance from message"""
        try:
            # Pattern: "The OBJECT is DISTANCE away"
            pattern = r"is ([\d.]+)m?\s*(?:meters?\s+)?away"
            match = re.search(pattern, message)
            
            if match:
                return float(match.group(1))
            return None
        except:
            return None

    def play_tones(self, message):
        """Play different tones based on distance"""
        try:
            self.get_logger().info(f'🎵 Tone for: "{message}"')
            
            distance = self.parse_distance(message)
            
            if distance is None:
                # Unknown message - single beep
                self.single_beep(800, 300)
                return
            
            # Distance-based tones
            if distance <= 1.0:
                # CLOSE - High urgent beeps
                self.rapid_beeps(1000, 100, 5)  # High pitch, fast
            elif distance <= 2.0:
                # MEDIUM - Medium beeps  
                self.medium_beeps(600, 200, 3)  # Medium pitch
            elif distance <= 3.0:
                # FAR - Low gentle beeps
                self.slow_beeps(400, 400, 2)    # Low pitch, slow
            else:
                # Very far - single low tone
                self.single_beep(300, 500)
                
        except Exception as e:
            self.get_logger().error(f'❌ Tone error: {e}')

    def single_beep(self, frequency, duration):
        """Single beep tone"""
        if self.beep_available:
            subprocess.run(['beep', '-f', str(frequency), '-l', str(duration)], 
                         capture_output=True)
        else:
            # Fallback to speaker-test tone
            subprocess.run(['speaker-test', '-t', 'sine', '-f', str(frequency), 
                          '-l', '1', '-s', '1'], capture_output=True, timeout=2)

    def rapid_beeps(self, frequency, duration, count):
        """Rapid urgent beeps for close objects"""
        for i in range(count):
            self.single_beep(frequency, duration)
            if i < count - 1:  # Don't wait after last beep
                subprocess.run(['sleep', '0.1'], capture_output=True)

    def medium_beeps(self, frequency, duration, count):
        """Medium paced beeps for medium distance"""
        for i in range(count):
            self.single_beep(frequency, duration)
            if i < count - 1:
                subprocess.run(['sleep', '0.3'], capture_output=True)

    def slow_beeps(self, frequency, duration, count):
        """Slow gentle beeps for far objects"""
        for i in range(count):
            self.single_beep(frequency, duration)
            if i < count - 1:
                subprocess.run(['sleep', '0.6'], capture_output=True)

def main(args=None):
    rclpy.init(args=args)
    node = Speaker()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('🛑 Musical Tone Speaker stopped')
    finally:
        rclpy.shutdown()

if __name__ == '__main__':
    main()