#!/usr/bin/env python3

# Main ROS2 library
import rclpy
from rclpy.node import Node
from vision_msgs.msg import Detection2DArray, Detection2D, ObjectHypothesisWithPose
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from ultralytics import YOLO
import cv2
import numpy as np

class Yolo_detection(Node):
    def __init__(self):
        super().__init__('yolo_detection_node')
        self.bridge = CvBridge()
        
        # Detection Model
        self.yolo_det_model = YOLO('yolov8n.pt')
        
        # Class names for display
        self.class_names = {
            0: "person", 1: "bicycle", 2: "car", 3: "motorcycle", 4: "airplane",
            5: "bus", 6: "train", 7: "truck", 8: "boat", 9: "traffic light",
            10: "fire hydrant", 11: "stop sign", 12: "parking meter", 13: "bench",
            14: "bird", 15: "cat", 16: "dog", 17: "horse", 18: "sheep",
            19: "cow", 20: "elephant", 21: "bear", 22: "zebra", 23: "giraffe",
            24: "backpack", 25: "umbrella", 26: "handbag", 27: "tie", 28: "suitcase",
            39: "bottle", 40: "wine glass", 41: "cup", 42: "fork", 43: "knife",
            44: "spoon", 45: "bowl", 56: "chair", 57: "couch", 58: "potted plant",
            59: "bed", 60: "dining table", 61: "toilet", 62: "tv", 63: "laptop",
            64: "mouse", 65: "remote", 66: "keyboard", 67: "cell phone", 72: "refrigerator"
        }
        
        # Camera subscriber
        self.camera_listener = self.create_subscription(
            Image,
            '/camera/image',
            self.camera_callback,
            10
        )
        
        # Detection publisher (same as before)
        self.detection_publisher = self.create_publisher(
            Detection2DArray,
            '/detection',
            10
        )
        
        # Display settings
        self.show_display = True  # Set to False to disable visual display
        
        self.get_logger().info('🎯 YOLO Detection Node with Visual Display initialized')
        self.get_logger().info('📺 Press "q" in the camera window to quit display')

    def draw_detections(self, image, yolo_results):
        """Draw bounding boxes and labels on the image"""
        display_image = image.copy()
        
        for result in yolo_results:
            if hasattr(result, 'boxes') and result.boxes is not None:
                for box in result.boxes:
                    # Get box coordinates
                    x1, y1, x2, y2 = box.xyxy[0].cpu().numpy()
                    confidence = float(box.conf[0])
                    class_id = int(box.cls[0])
                    
                    # Only draw if confidence is above threshold
                    if confidence >= 0.55:
                        # Get class name
                        class_name = self.class_names.get(class_id, f"class_{class_id}")
                        
                        # Choose color based on confidence
                        if confidence >= 0.8:
                            color = (0, 255, 0)  # Green for high confidence
                        elif confidence >= 0.7:
                            color = (0, 255, 255)  # Yellow for medium confidence
                        else:
                            color = (0, 165, 255)  # Orange for lower confidence
                        
                        # Draw bounding box
                        cv2.rectangle(display_image, (int(x1), int(y1)), (int(x2), int(y2)), color, 2)
                        
                        # Prepare label text
                        label = f"{class_name}: {confidence:.2f}"
                        
                        # Calculate text size for background
                        (text_width, text_height), baseline = cv2.getTextSize(
                            label, cv2.FONT_HERSHEY_SIMPLEX, 0.7, 2
                        )
                        
                        # Draw background rectangle for text
                        cv2.rectangle(
                            display_image,
                            (int(x1), int(y1) - text_height - 10),
                            (int(x1) + text_width, int(y1)),
                            color,
                            -1
                        )
                        
                        # Draw label text
                        cv2.putText(
                            display_image,
                            label,
                            (int(x1), int(y1) - 5),
                            cv2.FONT_HERSHEY_SIMPLEX,
                            0.7,
                            (0, 0, 0),  # Black text
                            2
                        )
        
        return display_image

    def camera_callback(self, msg):
        """When the camera images arrive"""
        # Convert ROS Image -> OpenCV
        cv_image = self.bridge.imgmsg_to_cv2(msg, "bgr8")
        
        # Run YOLO detection
        yolo_results = self.yolo_detection(cv_image)
        
        # Create ROS2 detection message (same as before)
        detection_msg = Detection2DArray()
        detection_msg.header = msg.header
        detection_msg.detections = []
        
        detection_count = 0
        for result in yolo_results:
            if hasattr(result, 'boxes') and result.boxes is not None:
                for box in result.boxes:
                    confidence = float(box.conf[0])
                    
                    # Only publish detections above threshold
                    if confidence >= 0.55:
                        detection_2d = Detection2D()
                        obj_hypothesis = ObjectHypothesisWithPose()
                        obj_hypothesis.hypothesis.class_id = str(int(box.cls[0]))
                        obj_hypothesis.hypothesis.score = confidence
                        detection_2d.results = [obj_hypothesis]
                        detection_msg.detections.append(detection_2d)
                        detection_count += 1
        
        # Publish detections
        self.detection_publisher.publish(detection_msg)
        self.get_logger().info(f'📡 Published {detection_count} detections')
        
        # Display camera feed with detections (if enabled)
        if self.show_display:
            display_image = self.draw_detections(cv_image, yolo_results)
            
            # Add status text to image
            status_text = f"Detections: {detection_count} | Press 'q' to quit"
            cv2.putText(
                display_image,
                status_text,
                (10, 30),
                cv2.FONT_HERSHEY_SIMPLEX,
                0.7,
                (255, 255, 255),
                2
            )
            
            # Show the image
            cv2.imshow('Smart Cane - YOLO Detection Feed', display_image)
            
            # Check for quit key
            key = cv2.waitKey(1) & 0xFF
            if key == ord('q'):
                self.get_logger().info('🛑 Display window closed by user')
                cv2.destroyAllWindows()
                self.show_display = False

    def yolo_detection(self, cv_img):
        """Run YOLO detection on the image"""
        detection_results = self.yolo_det_model.predict(cv_img, conf=0.55, iou=0.3, verbose=False)
        return detection_results

    def destroy_node(self):
        """Clean up when node is destroyed"""
        cv2.destroyAllWindows()
        super().destroy_node()

def main(args=None):
    # Initialize ROS2
    rclpy.init(args=args)
    
    # Create node
    node = Yolo_detection()
    
    try:
        # Spin the node
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('🛑 YOLO Detection node stopped by user')
    finally:
        # Cleanup
        cv2.destroyAllWindows()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()