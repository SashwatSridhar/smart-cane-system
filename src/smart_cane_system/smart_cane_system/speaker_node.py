#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import subprocess
import threading
import shlex

"""
Alternative speaker using system TTS commands
Often provides better Bluetooth audio quality than pyttsx3
"""

class Speaker(Node):
    def __init__(self):
        super().__init__('speaker_node')
        
        # Test which TTS system is available
        self.tts_command = self.find_best_tts()
        
        if self.tts_command:
            self.get_logger().info(f'🔊 Using system TTS: {self.tts_command[0]}')
            # Test announcement
            self.speak_system("Smart cane system TTS ready")
        else:
            self.get_logger().error('❌ No system TTS found')

        # Subscriber
        self.obstacle_fusion_listener = self.create_subscription(
            String,
            '/audio_command',
            self.speaker,
            10
        )

    def find_best_tts(self):
        """Find the best available system TTS command"""
        # Try different TTS systems in order of preference
        tts_options = [ #Different TTS options and the code finds which one is installed in the Linux System
            # espeak-ng (usually installed on Ubuntu)
            ['espeak-ng', '-s', '140', '-v', 'en'], #-s 140 is the speed which is 140 words per minute
            # espeak (fallback)
            ['espeak', '-s', '140', '-v', 'en'], #-v en is the voice which is in English
            # festival (if installed)
            ['festival', '--tts'],
            # spd-say (speech-dispatcher)
            ['spd-say', '-r', '-30']  # Slower rate -r -30 means speaker slower
        ]
        
        for cmd in tts_options:
            try:
                # Test if command exists
                result = subprocess.run([cmd[0], '--version'], capture_output=True, timeout=2) #checks whether the first cmd[0] which is the TTS option exists or not, return 0 if it exits
                if result.returncode == 0:
                    self.get_logger().info(f'✅ Found TTS: {cmd[0]}')
                    return cmd
            except:
                continue
                
        return None

    def speaker(self, msg):
        """Handle incoming audio messages"""
        if self.tts_command is None:
            return
            
        # Use threading to prevent blocking - speech outputs and node is able to continue to gain data without it the node freezes until speech is done
        threading.Thread(target=self.speak_system, args=(msg.data,)).start()

    def speak_system(self, message):
        """Speak using system TTS command"""
        try:
            self.get_logger().info(f'🗣️  Speaking: "{message}"')
            
            # Build command with message
            cmd = self.tts_command.copy() #copy the TTS command
            cmd.append(message) #append it to the cmd list
            
            # Execute TTS command
            subprocess.run(cmd, check=True, timeout=10) #have a subprocess to run it, check if its true and make sure the command must finish wiuthin 10 secs
            
        except subprocess.TimeoutExpired:
            self.get_logger().error('❌ TTS timeout')
        except subprocess.CalledProcessError as e:
            self.get_logger().error(f'❌ TTS command failed: {e}')
        except Exception as e:
            self.get_logger().error(f'❌ TTS error: {e}')

def main(args=None):
    rclpy.init(args=args)
    node = Speaker()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('🛑 System TTS speaker stopped')
    finally:
        rclpy.shutdown()

if __name__ == '__main__':
    main()
