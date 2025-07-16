import cv2

# Test different backends
backends = [
    (cv2.CAP_V4L2, "V4L2"),
    (cv2.CAP_GSTREAMER, "GStreamer"), 
    (cv2.CAP_FFMPEG, "FFmpeg"),
    (cv2.CAP_ANY, "Any")
]

for backend, name in backends:
    print(f"\n--- Testing {name} backend ---")
    cap = cv2.VideoCapture(0, backend)
    
    if cap.isOpened():
        # Try to set a common resolution
        cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
        cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
        
        ret, frame = cap.read()
        if ret:
            print(f"✅ {name} works! Shape: {frame.shape}")
            break
        else:
            print(f"❌ {name} opened but no frame")
    else:
        print(f"❌ {name} failed to open")
    
    cap.release()