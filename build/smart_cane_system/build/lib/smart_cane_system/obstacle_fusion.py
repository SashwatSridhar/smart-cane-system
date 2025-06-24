#!/usr/bin/env python3

# Main ROS2 library
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32, String
from vision_msgs.msg import Detection2DArray
import time

class ObstacleFusionNode(Node):
    def __init__(self):
        super().__init__('obstacle_fusion_node')

        # Initialize variables for the fusion node
        self.latest_distance = None
        self.latest_detection = None

        # Smart filtering variables to prevent audio spam
        self.last_announced_object = None
        self.last_announced_distance = None
        self.last_announcement_time = 0
        self.min_announcement_interval = 3.0  # 3 seconds between announcements

        # Initialize all the subscribers
        self.distance_listener = self.create_subscription(
            Float32,
            '/distance',
            self.distance_callback,
            10
        )

        self.detection_listener = self.create_subscription(
            Detection2DArray,
            '/detection',
            self.detection_callback,
            10
        )

        # Publishers
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

        # Timer
        self.timer = self.create_timer(
            0.1,
            self.process_fusion_timer
        )

        self.get_logger().info('Smart Obstacle Fusion Node initialized')
    
    def distance_callback(self, msg):
        """Callback when ultrasonic distance data arrives"""
        self.latest_distance = msg.data

    def detection_callback(self, msg):
        """Callback when YOLO detection data arrives"""
        self.latest_detection = msg
        
    def is_in_center_region(self, detection):
        """Check if detection bounding box is in center region of camera view"""
        # For now, we'll assume center region is middle 50% of image
        # You can adjust these values based on your camera setup
        
        # If detection has bbox information, use it
        # For now, we'll use a simple approach - just return True
        # TODO: Implement proper bounding box center checking when available
        return True  # Simplified for now
    
    def find_center_detection(self):
        """Find the most relevant detection in center of camera view"""
        if not hasattr(self.latest_detection, 'detections') or self.latest_detection.detections is None:
            return None
            
        if len(self.latest_detection.detections) == 0:
            return None

        center_detections = []
        
        # Find detections in center region
        for detection in self.latest_detection.detections:
            if detection.results is None or len(detection.results) == 0:
                continue
                
            if self.is_in_center_region(detection):
                center_detections.append(detection)
        
        # If we have center detections, return the highest confidence one
        if center_detections:
            best_center = max(center_detections, key=lambda x: x.results[0].hypothesis.score)
            return best_center
        
        # Fallback: return highest confidence from all detections
        all_valid_detections = []
        for detection in self.latest_detection.detections:
            if detection.results is not None and len(detection.results) > 0:
                all_valid_detections.append(detection)
        
        if all_valid_detections:
            return max(all_valid_detections, key=lambda x: x.results[0].hypothesis.score)
        
        return None
    
    def should_announce(self, current_distance, detected_object):
        """Smart filtering - only announce when necessary"""
        current_time = time.time()
        
        # Don't announce too frequently
        if current_time - self.last_announcement_time < self.min_announcement_interval:
            return False
        
        # Announce if NEW object detected
        if detected_object != self.last_announced_object:
            return True
            
        # Announce if distance changed significantly (>0.5m)
        if self.last_announced_distance is None:
            return True
            
        distance_change = abs(current_distance - self.last_announced_distance)
        if distance_change > 0.5:  # Significant change
            return True
            
        return False
    
    def process_fusion_timer(self):
        """Timer callback that runs fusion logic with smart filtering"""
        # Check if we have both sensors
        if self.latest_detection is None or self.latest_distance is None:
            return 

        # Get current distance (not historical closest)
        current_distance = self.latest_distance
        
        # Find most relevant detection (center-focused)
        center_detection = self.find_center_detection()
        
        if center_detection is None:
            return
            
        # Extract detection info
        confidence = center_detection.results[0].hypothesis.score
        class_id = center_detection.results[0].hypothesis.class_id
        detected_object = self.convert_id_to_name(class_id)
        
        # Only process if object is close enough and confident enough
        if current_distance <= 3.0 and confidence >= 0.75:
            # Check if we should announce (smart filtering)
            should_announce = self.should_announce(current_distance, detected_object)
            
            # Always send vibration for continuous feedback
            self.send_vibration_command_by_distance(current_distance)
            
            # Only send audio if filtering allows it
            if should_announce:
                self.send_audio_command(current_distance, detected_object)
                
                # Update tracking variables
                self.last_announced_object = detected_object
                self.last_announced_distance = current_distance
                self.last_announcement_time = time.time()
                
                self.get_logger().info(f"Announced: {detected_object} at {current_distance:.1f}m")
            else:
                self.get_logger().debug(f"Filtered: {detected_object} at {current_distance:.1f}m")

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

    def send_vibration_command_by_distance(self, distance):
        """Send appropriate vibration based on distance"""
        if distance <= 1:
            self.send_vibration_command("Fast")
        elif distance <= 2:
            self.send_vibration_command("Medium")
        elif distance <= 3:
            self.send_vibration_command("Slow")
    
    def send_audio_command(self, distance, detected_object):
        """Publish audio message to /audio_command topic"""
        msg = String()
        msg.data = f"The {detected_object} is {distance:.1f}m away"
        print(f"AUDIO: {msg.data}")  
        self.audio_command_publisher.publish(msg)

    def send_vibration_command(self, vibration_type):
        """Send vibration command"""
        vib_msg = String()
        vib_msg.data = vibration_type  # "Fast", "Medium", or "Slow"
        self.vibration_alert_publisher.publish(vib_msg)

    # Keep your original obstacle_fusion method for backwards compatibility/testing
    def obstacle_fusion(self, distance, yolo_confidence, detected_object):
        """Original fusion method - kept for testing"""
        if distance <= 1 and yolo_confidence >= 0.75:
            self.send_audio_command(distance, detected_object)
            self.send_vibration_command("Fast")
        elif distance <= 2 and yolo_confidence >= 0.75:
            self.send_audio_command(distance, detected_object)
            self.send_vibration_command("Medium")
        elif distance <= 3 and yolo_confidence >= 0.75:
            self.send_audio_command(distance, detected_object)
            self.send_vibration_command("Slow")    

def test(node):
    """Test the original fusion logic"""
    print("=" * 60)
    print("STARTING OBSTACLE FUSION TESTS")
    print("=" * 60)
    
    test_cases = [
        (0.5, 0.85, "person"),
        (1.8, 0.80, "car"),
        (2.7, 0.90, "bicycle"),
        (0.8, 0.60, "chair"),
        (0.3, 0.88, "motorcycle"),
        (3.0, 0.75, "bench"),
        (2.0, 0.82, "bus"),
        (1.0, 0.79, "truck"),
        (4.5, 0.65, "airplane"),
        (0.7, 0.91, "couch")
    ]
    
    for distance, yolo_confidence, detected_object in test_cases:
        node.obstacle_fusion(distance, yolo_confidence, detected_object)

def main(args=None):
    rclpy.init(args=args)
    node = ObstacleFusionNode()
    
    # Uncomment to run tests:
    # test(node)
    
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()