#!/usr/bin/env python3


# Main ROS2 library
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32, String
from vision_msgs.msg import Detection2DArray
import time

class ObstacleFusionNode(Node): #is a class that inherits the node properties
    def __init__(self):
        # TODO: Initialize the parent Node class with a node name
        super().__init__('obstacle_fusion_node') #creates the actual node

        #initialize variables for the fushion node
        self.latest_distance = None
        self.latest_detection = None

        #structure of creating subscribers
        '''
        self.subscriber_name = self.create_subscription(
        MessageType,           # What type of message
        '/topic_name',         # Which topic to listen to  
        self.callback_function, # What function to call when message arrives
        10                     # Queue size (usually 10 is fine)
    )
        '''

        #initialize all the subscribers
        self.distance_listener = self.create_subscription(  #subscriber name is the distance listener
            Float32,
            '/distance', #topic
            self.distance_callback,
            10
        )

        self.detection_listener = self.create_subscription(
            Detection2DArray,
            '/detection',
            self.detection_callback,
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

        self.vibration_alert_publisher = self.create_publisher(
            String,
            '/obstacle_alert',
            10
        )

        self.audio_command_publisher = self.create_publisher(
            String,
            '/audio_command',
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
            0.1,
            self.process_fusion_timer
        )



        
        # Log that the node started
        self.get_logger().info('Obstacle Fusion Node initialized')
    
    def distance_callback(self, msg):
        """Callback when ultrasonic distance data arrives"""
        # TODO: Store the distance data from msg.data
        self.latest_distance  = msg.data #.data for float values (just the value)


    def detection_callback(self, msg):
        """Callback when YOLO detection data arrives"""
        # TODO: Store the detection data 
        self.latest_detection = msg #just msg for Detection2DArray -> everything in the message
        
    
    def process_fusion_timer(self):
        """Timer callback that runs your fusion logic"""
        best_confidence = 0
        best_object = None

        # Check if we have both sensors
        if self.latest_detection is None or self.latest_distance is None:
            return 
        
        # Check if detections list exists. if it doesnt have attribute or detections is empty then return 
        if not hasattr(self.latest_detection, 'detections') or self.latest_detection.detections is None:
            return

        # Check if detections list is empty
        if len(self.latest_detection.detections) == 0:
            return

        # Find best detection
        for detection in self.latest_detection.detections:
            # Skip detections with no results
            if detection.results is None or len(detection.results) == 0:
                continue
            
            # Safely access the first result
            if detection.results[0].score > best_confidence:
                best_confidence = detection.results[0].score
                class_id = detection.results[0].id
                best_object = self.convert_id_to_name(class_id)
        
        # Call fusion (even if no detections found - let fusion handle it)
        self.obstacle_fusion(self.latest_distance, best_confidence, best_object)

    def convert_id_to_name(self, class_id):
        class_names = {
            0: "person",
            1: "bicycle", 
            2: "car",
            3: "motorcycle",
            4: "airplane",
            5: "bus",
            6: "train", 
            7: "truck",
            8: "boat",
            9: "traffic light",
            10: "fire hydrant",
            11: "stop sign",
            12: "parking meter",
            13: "bench",
            56: "chair",
            57: "couch", 
            58: "potted plant",
            59: "bed",
            60: "dining table",
            61: "toilet",
            62: "tv",
            72: "refrigerator"
        }
        return class_names.get(class_id, "unknown_object")
    

    

    def obstacle_fusion(self, distance, yolo_confidence, detected_object):
        if distance <= 1 and yolo_confidence >= 0.75:
            self.send_audio_command(distance, detected_object)
            self.send_vibration_command("Fast")
        elif distance <= 2 and yolo_confidence >= 0.75:
            self.send_audio_command(distance, detected_object)
            self.send_vibration_command("Medium")
        elif distance <= 3 and yolo_confidence >= 0.75:
            self.send_audio_command(distance, detected_object)
            self.send_vibration_command("Slow")    
                
    
    def send_audio_command(self, distance, detected_object):
        """Publish audio message to /audio_command topic"""
        msg = String()
        msg.data = f"The {detected_object} is {distance}m away"
        print(f"AUDIO: {msg.data}")  
        self.audio_command_publisher.publish(msg)

    
    def send_vibration_command(self, vibration_type):
        """Publish vibration command to /obstacle_alert topic"""

        vib_msg = String()

        if vibration_type == "Fast":
            vib_msg.data = f"Fast beats as you are less than 1m from the object"

        
        elif vibration_type == "Medium":
            vib_msg.data =  f"Medium beats as you are less than 2m from the object"

            
        elif vibration_type == "Slow":
            vib_msg.data =  f"Slow beats as you are less than 3m from the object"
        
        print(f"VIBRATION: {vib_msg.data}") 
        self.vibration_alert_publisher.publish(vib_msg)

def test(node):
        """
        Run 20 test cases for the obstacle fusion function
        Tests various combinations of distance, confidence, and object types
        """
    
        print("=" * 60)
        print("STARTING OBSTACLE FUSION TESTS")
        print("=" * 60)
        
        

        test_cases = [
            # Test Case 1: Very close person - should trigger all alerts
            (0.5, 0.85, "person"),
            
            # Test Case 2: Medium distance car - should trigger 3m and 2m alerts
            (1.8, 0.80, "car"),
            
            # Test Case 3: Far bicycle - should trigger 3m alert only
            (2.7, 0.90, "bicycle"),
            
            # Test Case 4: Close but low confidence - should not trigger
            (0.8, 0.60, "chair"),
            
            # Test Case 5: Very close motorcycle - should trigger all alerts
            (0.3, 0.88, "motorcycle"),
            
            # Test Case 6: Edge case - exactly 3m with good confidence
            (3.0, 0.75, "bench"),
            
            # Test Case 7: Edge case - exactly 2m with good confidence  
            (2.0, 0.82, "bus"),
            
            # Test Case 8: Edge case - exactly 1m with good confidence
            (1.0, 0.79, "truck"),
            
            # Test Case 9: Far object with low confidence - no alerts
            (4.5, 0.65, "airplane"),
            
            # Test Case 10: Close couch - should trigger all alerts
            (0.7, 0.91, "couch"),
            
            # Test Case 11: Medium distance table - should trigger 3m and 2m
            (1.5, 0.86, "dining table"),
            
            # Test Case 12: Far traffic light - should trigger 3m only
            (2.9, 0.77, "traffic light"),
            
            # Test Case 13: Very low confidence, close distance - no alerts
            (0.9, 0.45, "potted plant"),
            
            # Test Case 14: Borderline confidence - exactly 0.75
            (1.2, 0.75, "fire hydrant"),
            
            # Test Case 15: Close stop sign - should trigger all alerts
            (0.4, 0.93, "stop sign"),
            
            # Test Case 16: Medium distance TV - should trigger 3m and 2m
            (1.9, 0.81, "tv"),
            
            # Test Case 17: Far bed with high confidence - should trigger 3m only
            (2.8, 0.89, "bed"),
            
            # Test Case 18: Close parking meter - should trigger all alerts
            (0.6, 0.84, "parking meter"),
            
            # Test Case 19: Just outside 3m range - no alerts
            (3.2, 0.87, "refrigerator"),
            
            # Test Case 20: Boat detection - should trigger 3m and 2m
            (1.7, 0.76, "boat")
            ]
        
        for distance, yolo_confidence, detected_object in test_cases:
            node.obstacle_fusion(distance, yolo_confidence, detected_object)

        

def main(args=None):
    # TODO: Initialize ROS2
    rclpy.init(args = args)
    # TODO: Create your node
    node = ObstacleFusionNode()
    #test
    test(node)
    # TODO: Spin the node (keep it running)
    rclpy.spin(node)
    # TODO: Cleanup when done
    rclpy.shutdown()

if __name__ == '__main__':
    main()