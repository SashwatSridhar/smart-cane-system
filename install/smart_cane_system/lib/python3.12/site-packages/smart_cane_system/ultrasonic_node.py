"""
create the node
configer the pins
create the publisher
create a callback when the distance arrives
"""


#All the imports
#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32
import lgpio as GPIO
import time


class Ultrasonic(Node):


    def __init__(self):
        super.__init__('ultrasonic_node')


        self.h = GPIO.gpiochip_open(0)
        self.TRIG = 18
        self.ECHO = 24
        GPIO.gpio_claim_output(self.h, self.TRIG)
        GPIO.gpio_claim_input(self.h, self.ECHO)

    

        #Publisher Structure
        '''
            self.publisher_name = self.create_publisher(
                MessageType,      # What type of message to send
                '/topic_name',    # Which topic to publish to
                10               # Queue size (usually 10 is fine)
                )
                Note: NO callback function needed for publishers!
        '''
            
        self.distance_publisher = self.create_publisher(
            Float32,
            '/distance',
            10
        )


        #structure for timer
        '''
            self.name = self.create_timer(
            # Time interval 
            self.callback_function
        )
        '''

        self.timer = self.create_timer(
                0.2,
                self.timer_callback
            )
        

        self.get_logger().info('Ultrasonic Node initialized')


    def timer_callback(self):
        GPIO.gpio_write(self.h, self.TRIG, 0) #low self.TRIGger off
        time.sleep(2)

        GPIO.gpio_write(self.h, self.TRIG, 1)
        time.sleep(0.00001)
        GPIO.gpio_write(self.h, self.TRIG, 0)


        while GPIO.gpio_read(self.h, self.ECHO) == 0: #when there is no ECHO
            pulse_start = time.time()

        while GPIO.gpio_read(self.h, self.ECHO) == 1: #when there is ECHO
            pulse_end = time.time()

        pulse_duration =  pulse_end - pulse_start

        #formula: distance = (time x speed) / 2 -> speed of sound is 343 m/s
        distance = (pulse_duration * (343)) / 2 #formula for ultrasonic sensor to measure distance


        distance_msg = Float32()
        distance_msg.data = distance
        self.distance_publisher.publish(distance_msg)


def main(args=None):
    # TODO: Initialize ROS2
    rclpy.init(args = args)
    # TODO: Create your node
    node = Ultrasonic()
    # TODO: Spin the node (keep it running)
    rclpy.spin(node)
    # TODO: Cleanup when done
    rclpy.shutdown()

if __name__ == '__main__':
    main()







