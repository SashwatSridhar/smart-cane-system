#all imports

#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2





class Camera(Node):
    def __init__(self):
        super.__init__('camera_node')
        self.bridge = CvBridge() 
        self.cap = cv2.VideoCapture(0) #captures using the first camera on your device

        #check if image capture was sucessful
        success_flag, img_data = self.cap.read() 

        if success_flag == True: #returns true or false if the frame is read correctly 
            self.get_logger().info('The camera  works properly')  

        else:
            self.get_logger().info("The camera didn't work properly (frame is not read correctly)")

        

        #Publisher Structure
        '''
        self.publisher_name = self.create_publisher(
            MessageType,      # What type of message to send
            '/topic_name',    # Which topic to publish to
            10               # Queue size (usually 10 is fine)
        )
        Note: NO callback function needed for publishers!
        '''

        self.cam_publisher = self.create_publisher(
            Image,
            '/camera/image',
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

        # Log that the node started
        self.get_logger().info('Camera Node initialized')


    def timer_callback(self):
            
            if not self.cap.isOpened():
                self.get_logger().error("Cannot open camera")
                return  # Just skip this timer cycle, don't crash the whole node

            #check if image capture was sucessful
            success_flag, img_data = self.cap.read() 

            if success_flag == True: #returns true or false if the frame is read correctly 
                cv_image = self.bridge.cv2_to_imgmsg(img_data, "bgr8")  # Convert ROS Image -> OpenCV (one line!) 
                #This image uses Blue-Green-Red color format with 8 bits per channel (found in Opencv documentation)
                
                #publish to topic
                self.cam_publisher.publish(cv_image)
                self.get_logger().info(f'Published images')

            else:
                self.get_logger().info("The camera didn't work properly (frame is not read correctly)")

            
def main(args=None):
    # TODO: Initialize ROS2
    rclpy.init(args = args)
    # TODO: Create your node
    node = Camera()
    # TODO: Spin the node (keep it running)
    rclpy.spin(node)
    # TODO: Cleanup when done
    rclpy.shutdown()

if __name__ == '__main__':
    main()




           
