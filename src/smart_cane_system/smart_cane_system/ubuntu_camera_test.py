#!/usr/bin/env python3

import cv2
import os

print("=== UBUNTU CAMERA TEST ===")

# Check for video devices
print("\n1. Found video devices:")
video_devices = []
for i in range(40):  # Check up to video39
    device_path = f"/dev/video{i}"
    if os.path.exists(device_path):
        video_devices.append(i)
        print(f"  /dev/video{i}")

print(f"Total video devices: {len(video_devices)}")

# Test video devices starting from the lowest numbers
print("\n2. Testing cameras with OpenCV...")

working_cameras = []

for device_num in video_devices:
    print(f"\nTesting /dev/video{device_num}...")
    
    cap = cv2.VideoCapture(device_num)
    
    if cap.isOpened():
        print(f"  ✓ Opened /dev/video{device_num}")
        
        # Try to capture a frame
        ret, frame = cap.read()
        if ret and frame is not None:
            height, width = frame.shape[:2]
            print(f"  ✓ Captured frame: {width}x{height}")
            
            # Save test image
            filename = f"test_video{device_num}.jpg"
            cv2.imwrite(filename, frame)
            print(f"  ✓ Saved: {filename}")
            
            working_cameras.append(device_num)
            
            # Get camera properties
            fps = cap.get(cv2.CAP_PROP_FPS)
            print(f"  Camera FPS: {fps}")
            
        else:
            print(f"  ✗ Could not capture frame from /dev/video{device_num}")
    else:
        print(f"  ✗ Could not open /dev/video{device_num}")
    
    cap.release()

print(f"\n=== SUMMARY ===")
print(f"Working cameras found: {working_cameras}")

if working_cameras:
    best_camera = working_cameras[0]  # Use the first working one
    print(f"Recommended camera device: /dev/video{best_camera}")
    print(f"Use camera index {best_camera} in your ROS2 code")
else:
    print("No working cameras found!")

print("\n=== TEST COMPLETE ===")