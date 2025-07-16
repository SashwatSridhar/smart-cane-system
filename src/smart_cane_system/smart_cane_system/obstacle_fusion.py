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
        
        # 📳 ADD THESE VIBRATION STATE VARIABLES:
        self.last_vibration_type = None
        self.last_vibration_distance = None
        self.last_vibration_time = 0
        self.min_vibration_interval = 1.0  # 1 second between vibration changes
        self.vibration_active = False
        
        self.distance_history = []
        self.distance_history_size = 5

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
        
    def is_stable_background_reading(self, current_distance):
        """Check if distance reading is stable background (floor/wall reflection)"""
        self.distance_history.append(current_distance)
        if len(self.distance_history) > self.distance_history_size:
            self.distance_history.pop(0)
        
        if len(self.distance_history) >= 3:
            # Calculate standard deviation
            import statistics
            std_dev = statistics.stdev(self.distance_history)
            
            # If readings are very stable (low variation), it's probably background
            if std_dev < 0.1 and current_distance > 1.8:  # Very stable + far = background
                return True
        
        return False
        
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
    
    def should_vibrate(self, current_distance, vibration_type):
        
        current_time = time.time()
        
        # Don't change vibration too frequently
        if current_time - self.last_vibration_time < self.min_vibration_interval:
            return False
        
        # Vibrate if NEW vibration type needed
        if vibration_type != self.last_vibration_type:
            return True
            
        # Vibrate if distance changed significantly (>0.3m)
        if self.last_vibration_distance is None:
            return True
            
        distance_change = abs(current_distance - self.last_vibration_distance)
        if distance_change > 0.3:  # Significant distance change
            return True
            
        return False
    
    def determine_vibration_type(self, distance):
        """Determine what vibration type should be active"""
        if distance <= 1:
            return "Fast"
        elif distance <= 2:
            return "Medium"
        elif distance <= 2.4:
            return "Slow"
        else:
            return None  # No vibration needed
    
    def process_fusion_timer(self):
        """Timer callback with improved background rejection"""
        # Check if we have both sensors
        if self.latest_detection is None or self.latest_distance is None:
            if self.vibration_active:
                self.send_vibration_command("Stop")
                self.vibration_active = False
                self.last_vibration_type = None
            return 

        current_distance = self.latest_distance
        center_detection = self.find_center_detection()
        
        # 🔧 STRICTER DISTANCE THRESHOLD: Reduce to 2.0m to avoid floor reflections
        if current_distance > 2.0:  # Changed from 2.4 to 2.0
            if self.vibration_active:
                self.send_vibration_command("Stop")
                self.vibration_active = False
                self.last_vibration_type = None
            return
        
        # 🔧 EVEN STRICTER: Only trust ultrasonic for very close objects
        # MODE 1: ULTRASONIC-ONLY (safety - trust for very close objects)
        if current_distance <= 1.2:  # Changed from 1.5 to 1.2 - only very close
            vibration_type = self.determine_vibration_type(current_distance)
            if self.should_vibrate(current_distance, vibration_type):
                self.send_vibration_command(vibration_type)
                self.last_vibration_type = vibration_type
                self.last_vibration_distance = current_distance
                self.last_vibration_time = time.time()
                self.vibration_active = True
                
                # Use generic object name if no good camera detection
                if center_detection and center_detection.results[0].hypothesis.score >= 0.75:
                    class_id = int(center_detection.results[0].hypothesis.class_id)
                    detected_object = self.convert_id_to_name(class_id)
                else:
                    detected_object = "object"
                    
                self.get_logger().info(f"📳 Ultrasonic mode: {vibration_type} for {detected_object} at {current_distance:.1f}m")
        
        # MODE 2: COMBINED MODE - MUCH STRICTER
        elif center_detection and center_detection.results[0].hypothesis.score >= 0.85:  # Increased confidence from 0.75 to 0.85
            class_id = int(center_detection.results[0].hypothesis.class_id)
            detected_object = self.convert_id_to_name(class_id)
            
            vibration_type = self.determine_vibration_type(current_distance)
            if vibration_type and self.should_vibrate(current_distance, vibration_type):
                self.send_vibration_command(vibration_type)
                self.last_vibration_type = vibration_type
                self.last_vibration_distance = current_distance
                self.last_vibration_time = time.time()
                self.vibration_active = True
                self.get_logger().info(f"📳 Combined mode: {vibration_type} for {detected_object} at {current_distance:.1f}m")
            
            # 🔊 AUDIO LOGIC (only in combined mode)
            if self.should_announce(current_distance, detected_object):
                self.send_audio_command(current_distance, detected_object)
                self.last_announced_object = detected_object
                self.last_announced_distance = current_distance
                self.last_announcement_time = time.time()
                self.get_logger().info(f"🔊 Announced: {detected_object} at {current_distance:.1f}m")
        
        else:
            # No good detection or confidence too low - stop vibration
            if self.vibration_active:
                self.send_vibration_command("Stop")
                self.vibration_active = False
                self.last_vibration_type = None

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
        elif distance <= 2.4:
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
        if distance <= 1.0 and yolo_confidence >= 0.75:
            self.send_audio_command(distance, detected_object)
            self.send_vibration_command("Fast")
        elif distance <= 2.0 and yolo_confidence >= 0.75:
            self.send_audio_command(distance, detected_object)
            self.send_vibration_command("Medium")
        elif distance <= 2.4 and yolo_confidence >= 0.75:
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
    #test(node)
    
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()