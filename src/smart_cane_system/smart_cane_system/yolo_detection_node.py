#!/usr/bin/env python3


# Main ROS2 library
import rclpy
from rclpy.node import Node
from vision_msgs.msg import Detection2DArray, Detection2D, ObjectHypothesisWithPose
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from ultralytics import YOLO 
import cv2


class Yolo_detection(Node):
    def __init__(self):
        super().__init__('yolo_detection_node')
        self.bridge = CvBridge() 
        #Detection Model
        self.yolo_det_model = YOLO('yolov8n.pt')
        
        #structure of creating subscribers
        '''
        self.subscriber_name = self.create_subscription(
        MessageType,           # What type of message
        '/topic_name',         # Which topic to listen to  
        self.callback_function, # What function to call when message arrives
        10                     # Queue size (usually 10 is fine)
        )
        '''

        self.camera_listener = self.create_subscription(
            Image,
            '/camera/image',
            self.camera_callback,
            10
        )

        #Publisher Structure
        '''
        self.publisher_name = self.create_publisher(
            MessageType,      # What type of message to send
            '/topic_name',    # Which topic to publish to
            10               # Queue size (usually 10 is fine)
        )
        Note: NO callback function needed for publishers!
        '''

        self.detection_publisher = self.create_publisher(
            Detection2DArray,
            '/detection',
            10
        )

         # Log that the node started
        self.get_logger().info('Yolo Detection Node initialized')


    #callback functions

    def camera_callback(self, msg):

        '''When the camera images arrive'''
        # Convert ROS Image -> OpenCV (one line!)
        cv_image = self.bridge.imgmsg_to_cv2(msg, "bgr8")
        
        # Run YOLO on OpenCV image
        yolo_results = self.yolo_detection(cv_image)

        detection_msg = Detection2DArray()
        detection_msg.header = msg.header  # Copy timestamp info
        detection_msg.detections = [] #detections get stored here

        for result in yolo_results:
            if hasattr(result, 'boxes') and result.boxes is not None:
                for box in result.boxes: #for each box
                    detection_2d = Detection2D() #create a detection object
                    obj_hypothesis = ObjectHypothesisWithPose() #create a hypothesis object as its not 100% so its making a guess
                    obj_hypothesis.hypothesis.class_id = str(int(box.cls[0])) #get the hypothesis of the class_id of the detection 
                    obj_hypothesis.hypothesis.score = float(box.conf[0]) #get the hypothesis of the confidence score of the detection
                    detection_2d.results = [obj_hypothesis] #the results for the detection object can be found in the hypothesis object
                    detection_msg.detections.append(detection_2d) #put the results into the detections list
        
        self.detection_publisher.publish(detection_msg) #publish the detection messages to the detection topic
        self.get_logger().info(f'Published {len(detection_msg.detections)} detections')
        
        

        


    #yolo function

    """Psudo code for the yolo function:
        
        the yolo function takes in the cv image 
        makes a prediction and stores that into a results variable
        """

    def yolo_detection(self, cv_img):
        detection_results = self.yolo_det_model.predict(cv_img, conf=0.55, iou=0.3)
        return detection_results


def main(args=None):
    # TODO: Initialize ROS2
    rclpy.init(args = args)
    # TODO: Create your node
    node = Yolo_detection()
    # TODO: Spin the node (keep it running)
    rclpy.spin(node)
    # TODO: Cleanup when done
    rclpy.shutdown()

if __name__ == '__main__':
    main()









