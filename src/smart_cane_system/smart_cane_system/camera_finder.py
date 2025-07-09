import libcamera
import time

print("Testing Python libcamera bindings...")

try:
    # Create camera manager
    cm = libcamera.CameraManager.singleton()
    
    # List available cameras
    cameras = cm.cameras
    print(f"Found {len(cameras)} camera(s)")
    
    if len(cameras) > 0:
        # Use the first camera
        camera = cameras[0]
        print(f"Camera: {camera.id}")
        
        # Acquire the camera
        ret = camera.acquire()
        if ret == 0:
            print("Camera acquired successfully!")
            
            # Generate configuration
            config = camera.generate_configuration([libcamera.StreamRole.Viewfinder])
            
            # Configure the camera
            ret = camera.configure(config)
            if ret == 0:
                print("Camera configured successfully!")
                print("Your camera is working with libcamera!")
            else:
                print("Failed to configure camera")
            
            camera.release()
        else:
            print("Failed to acquire camera")
    else:
        print("No cameras found")
        
except Exception as e:
    print(f"Error: {e}")