#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2

class Camera(Node):
    def __init__(self):
        super().__init__('camera_node')
        self.bridge = CvBridge()
        
        # Try multiple camera indices automatically
        self.camera_index = None
        self.cap = None
        
        # List of common camera indices to try
        camera_indices_to_try = [0, 1, 2, 4, 6, 8]
        
        self.get_logger().info('🔍 Searching for available camera...')
        
        for index in camera_indices_to_try:
            self.get_logger().info(f'   Trying camera index {index}...')
            test_cap = cv2.VideoCapture(index)
            
            if test_cap.isOpened():
                success_flag, img_data = test_cap.read()
                
                if success_flag and img_data is not None:
                    self.camera_index = index
                    self.cap = test_cap
                    height, width = img_data.shape[:2]
                    self.get_logger().info(f'✅ Camera {index} works! Resolution: {width}x{height}')
                    break
                else:
                    self.get_logger().info(f'   Camera {index} opens but cannot read frames')
                    test_cap.release()
            else:
                self.get_logger().info(f'   Camera {index} cannot be opened')
                test_cap.release()
        
        # Check if we found a working camera
        if self.camera_index is None or self.cap is None:
            self.get_logger().error('❌ No working camera found!')
            self.get_logger().error('   Please run camera_finder.py to diagnose camera issues')
            return
        
        self.get_logger().info(f'🎥 Using camera index {self.camera_index}')
        
        # Publisher
        self.cam_publisher = self.create_publisher(
            Image,
            '/camera/image',
            10
        )
        
        # Timer
        self.timer = self.create_timer(
            0.2,  # 5 FPS - good balance for processing
            self.timer_callback
        )
        
        self.get_logger().info('📷 Camera Node initialized successfully')

    def timer_callback(self):
        if self.cap is None or not self.cap.isOpened():
            self.get_logger().error("❌ Camera not available")
            return
        
        # Read frame
        success_flag, img_data = self.cap.read()
        
        if success_flag and img_data is not None:
            try:
                # Convert OpenCV image to ROS message
                cv_image = self.bridge.cv2_to_imgmsg(img_data, "bgr8")
                
                # Publish to topic
                self.cam_publisher.publish(cv_image)
                
                # Less verbose logging - only log occasionally
                if not hasattr(self, 'frame_count'):
                    self.frame_count = 0
                
                self.frame_count += 1
                if self.frame_count % 25 == 0:  # Log every 5 seconds at 5fps
                    self.get_logger().info(f'📸 Published {self.frame_count} frames')
                
            except Exception as e:
                self.get_logger().error(f'❌ Error converting/publishing frame: {e}')
        else:
            self.get_logger().warn("⚠️ Failed to read camera frame")

    def destroy_node(self):
        """Clean up camera when node is destroyed"""
        if self.cap is not None:
            self.cap.release()
            self.get_logger().info('🛑 Camera released')
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = Camera()
    
    # Only spin if camera was successfully initialized
    if node.cap is not None:
        try:
            rclpy.spin(node)
        except KeyboardInterrupt:
            node.get_logger().info('🛑 Camera node stopped by user')
        finally:
            node.destroy_node()
            rclpy.shutdown()
    else:
        node.get_logger().error('🚫 Camera node failed to initialize - exiting')
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()