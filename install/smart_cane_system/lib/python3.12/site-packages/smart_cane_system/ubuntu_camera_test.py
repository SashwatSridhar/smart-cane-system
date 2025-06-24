#!/usr/bin/env python3
import cv2
import os
import time
import numpy as np

print("=== SMART CANE CAMERA TEST ===")
print("Testing camera functionality for obstacle detection system")

# Check for video devices
print("\n1. Scanning for video devices...")
video_devices = []
for i in range(40):  # Check up to video39
    device_path = f"/dev/video{i}"
    if os.path.exists(device_path):
        video_devices.append(i)
        print(f"   Found: /dev/video{i}")

print(f"Total video devices found: {len(video_devices)}")

if not video_devices:
    print("❌ No video devices found! Check camera connection.")
    exit(1)

# Test video devices starting from the lowest numbers
print("\n2. Testing camera functionality...")
working_cameras = []
camera_details = {}

for device_num in video_devices:
    print(f"\n--- Testing /dev/video{device_num} ---")
    
    try:
        cap = cv2.VideoCapture(device_num)
        
        if not cap.isOpened():
            print(f"   ❌ Could not open /dev/video{device_num}")
            continue
            
        print(f"   ✅ Successfully opened /dev/video{device_num}")
        
        # Get camera properties
        width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
        height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
        fps = cap.get(cv2.CAP_PROP_FPS)
        
        print(f"   📐 Resolution: {width}x{height}")
        print(f"   🎬 FPS: {fps}")
        
        # Test frame capture with timing
        print("   📸 Testing frame capture...")
        start_time = time.time()
        ret, frame = cap.read()
        capture_time = (time.time() - start_time) * 1000  # Convert to ms
        
        if not ret or frame is None:
            print(f"   ❌ Could not capture frame from /dev/video{device_num}")
            cap.release()
            continue
            
        print(f"   ✅ Frame captured successfully ({capture_time:.1f}ms)")
        
        # Image quality checks
        print("   🔍 Analyzing image quality...")
        
        # Check if image is too dark or too bright
        mean_brightness = frame.mean()
        if mean_brightness < 20:
            print(f"   ⚠️  Warning: Image very dark (brightness: {mean_brightness:.1f})")
        elif mean_brightness > 200:
            print(f"   ⚠️  Warning: Image very bright (brightness: {mean_brightness:.1f})")
        else:
            print(f"   ✅ Good brightness level ({mean_brightness:.1f})")
        
        # Check if image has content (not just noise)
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        edges = cv2.Canny(gray, 50, 150)
        edge_density = np.sum(edges > 0) / (width * height)
        
        if edge_density < 0.01:
            print(f"   ⚠️  Warning: Low detail in image (may be pointing at blank surface)")
        else:
            print(f"   ✅ Good detail level detected")
        
        # Test multiple frame capture for consistency
        print("   🔄 Testing capture consistency...")
        successful_captures = 0
        capture_times = []
        
        for i in range(5):
            start = time.time()
            ret, test_frame = cap.read()
            capture_times.append((time.time() - start) * 1000)
            if ret and test_frame is not None:
                successful_captures += 1
        
        avg_capture_time = np.mean(capture_times)
        print(f"   📊 Capture success rate: {successful_captures}/5")
        print(f"   ⏱️  Average capture time: {avg_capture_time:.1f}ms")
        
        # Save test image with timestamp
        timestamp = time.strftime("%Y%m%d_%H%M%S")
        filename = f"smart_cane_test_video{device_num}_{timestamp}.jpg"
        cv2.imwrite(filename, frame)
        print(f"   💾 Test image saved: {filename}")
        
        # Store camera details
        camera_details[device_num] = {
            'resolution': (width, height),
            'fps': fps,
            'brightness': mean_brightness,
            'capture_time': avg_capture_time,
            'success_rate': successful_captures,
            'edge_density': edge_density
        }
        
        working_cameras.append(device_num)
        
        # Optional: Show preview (uncomment if you want to see camera feed)
        # print("   👁️  Showing 3-second preview...")
        # cv2.imshow(f'Camera {device_num} Preview', frame)
        # cv2.waitKey(3000)
        # cv2.destroyAllWindows()
        
    except Exception as e:
        print(f"   ❌ Error testing /dev/video{device_num}: {e}")
    
    finally:
        cap.release()

print(f"\n" + "="*50)
print("🎯 SMART CANE CAMERA RECOMMENDATIONS")
print("="*50)

if not working_cameras:
    print("❌ No working cameras found!")
    print("🔧 Troubleshooting tips:")
    print("   • Check camera is properly connected")
    print("   • Try 'lsusb' to see if camera is detected")
    print("   • Check camera permissions")
    exit(1)

print(f"✅ Found {len(working_cameras)} working camera(s): {working_cameras}")

# Rank cameras for smart cane use
print(f"\n📋 Camera Performance Analysis:")
for device_num in working_cameras:
    details = camera_details[device_num]
    print(f"\n📷 /dev/video{device_num}:")
    print(f"   Resolution: {details['resolution'][0]}x{details['resolution'][1]}")
    print(f"   Capture speed: {details['capture_time']:.1f}ms (target: <50ms)")
    print(f"   Reliability: {details['success_rate']}/5 captures")
    print(f"   Image quality: {'Good' if 50 < details['brightness'] < 150 else 'Check lighting'}")

# Recommend best camera
if working_cameras:
    # Score cameras based on smart cane requirements
    best_camera = None
    best_score = -1
    
    for device_num in working_cameras:
        details = camera_details[device_num]
        
        # Scoring criteria for smart cane
        score = 0
        
        # Prefer faster capture times
        if details['capture_time'] < 30:
            score += 3
        elif details['capture_time'] < 50:
            score += 2
        elif details['capture_time'] < 100:
            score += 1
            
        # Prefer reliable capture
        score += details['success_rate']
        
        # Prefer good image quality
        if 50 < details['brightness'] < 150:
            score += 2
            
        # Prefer reasonable resolution (not too high, not too low)
        width, height = details['resolution']
        total_pixels = width * height
        if 300000 < total_pixels < 2000000:  # ~640x480 to ~1920x1080 range
            score += 2
            
        if score > best_score:
            best_score = score
            best_camera = device_num

    print(f"\n🏆 RECOMMENDED CAMERA FOR SMART CANE:")
    print(f"   📷 Use /dev/video{best_camera} (camera index {best_camera})")
    print(f"   🔧 Update your camera_node.py:")
    print(f"      self.cap = cv2.VideoCapture({best_camera})")
    
    # Smart cane specific recommendations
    details = camera_details[best_camera]
    print(f"\n💡 Smart Cane Optimization Tips:")
    
    if details['capture_time'] > 50:
        print("   ⚠️  Consider reducing resolution for faster capture")
        
    if details['brightness'] < 50:
        print("   💡 Add LED lighting for better night detection")
        
    if any(details['resolution'][i] > 1280 for i in [0,1]):
        print("   💡 Consider 640x480 resolution for faster YOLO processing")

print(f"\n✅ Camera testing complete!")
print(f"🚀 Ready to integrate with your smart cane ROS2 system")

# Create a summary file
with open("camera_test_results.txt", "w") as f:
    f.write("Smart Cane Camera Test Results\n")
    f.write("="*40 + "\n")
    f.write(f"Working cameras: {working_cameras}\n")
    f.write(f"Recommended camera: /dev/video{best_camera}\n")
    f.write(f"Use camera index {best_camera} in ROS2 code\n")

print(f"📄 Results saved to: camera_test_results.txt")