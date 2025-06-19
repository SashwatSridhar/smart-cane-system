#imports

#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import pyttsx3


"""
Create the node
create a subscriber that subs to the audio_command topic
create a callback that receives the string message with the detect object and the distance
convert that text to speech use it on the speaker
"""

class Speaker(Node):
    def __init__(self):
        super().__init__('speaker_node')
        self.engine = pyttsx3.init()


        #structure of creating subscribers
        '''
            self.subscriber_name = self.create_subscription(
            MessageType,           # What type of message
            '/topic_name',         # Which topic to listen to  
            self.callback_function, # What function to call when message arrives
            10                     # Queue size (usually 10 is fine)
            )
        '''

        self.obstacle_fushion_listener = self.create_subscription(
            String,
            '/audio_command',
            self.speaker,
            10
        )


    def speaker(self, msg):
        self.engine.say(msg.data) #say() method to add text we want to be spoken
        self.engine.runAndWait() #runAndWait() to make the engine process the speech.


def main(args=None):
    # TODO: Initialize ROS2
    rclpy.init(args = args)
    # TODO: Create your node
    node = Speaker()
    # TODO: Spin the node (keep it running)
    rclpy.spin(node)
    # TODO: Cleanup when done
    rclpy.shutdown()

if __name__ == '__main__':
    main()
