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
from gpiozero import DistanceSensor
import time


class Ultrasonic(Node):
    def __init__(self):
        super().__init__('ultrasonic_node')

        # Configure the pins using gpiozero (Pi 5 compatible)
        try:
            self.sensor = DistanceSensor(echo=24, trigger=18)
            self.get_logger().info('✅ Ultrasonic sensor pins configured')
        except Exception as e:
            self.get_logger().error(f'❌ Failed to configure sensor: {e}')
            return

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
        """Callback when the distance measurement timer triggers"""
        try:
            # Get distance using gpiozero (handles all the GPIO operations internally)
            distance = self.sensor.distance  # Returns distance in meters
            
            # Validate the reading (sensor sometimes gives bad readings)
            if 0.02 <= distance <= 4.0:  # Valid range: 2cm to 4m
                distance_msg = Float32()
                distance_msg.data = distance
                self.distance_publisher.publish(distance_msg)
                self.get_logger().info(f'Published distance: {distance:.3f}m')
            else:
                self.get_logger().warn(f'Invalid distance reading: {distance:.3f}m')
                
        except Exception as e:
            self.get_logger().error(f'Sensor error: {e}')


def main(args=None):

    
    # TODO: Initialize ROS2
    rclpy.init(args=args)
    # TODO: Create your node
    node = Ultrasonic()
    # TODO: Spin the node (keep it running)
    rclpy.spin(node)
    # TODO: Cleanup when done
    rclpy.shutdown()

if __name__ == '__main__':
    main()