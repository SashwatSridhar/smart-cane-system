#!/bin/bash

echo "🦯 SMART CANE SYSTEM LAUNCHER"
echo "=============================="
echo "Starting all nodes automatically..."
echo ""

# Create logs directory
mkdir -p logs

# Function to cleanup processes on exit
cleanup() {
    echo ""
    echo "🛑 Stopping Smart Cane System..."
    echo "Terminating all processes..."
    
    # Kill all background processes
    jobs -p | xargs -r kill
    
    # Wait a moment for graceful shutdown
    sleep 2
    
    # Force kill any remaining ROS2 processes
    pkill -f "camera_node"
    pkill -f "yolo_detection_node" 
    pkill -f "ultrasonic_node"
    pkill -f "obstacle_fusion"
    pkill -f "vibration_node"
    pkill -f "speaker_node"
    
    echo "✅ Smart Cane System stopped"
    echo "📋 Check logs/ directory for any error messages"
    exit 0
}

# Set trap to cleanup on Ctrl+C or script exit
trap cleanup SIGINT SIGTERM EXIT

# Check if ROS2 is sourced
if ! command -v ros2 &> /dev/null; then
    echo "🔧 Sourcing ROS2 environment..."
    source /opt/ros/jazzy/setup.bash
fi

# Source workspace
echo "🔧 Sourcing workspace..."
source ~/smart-cane-system/install/setup.bash

echo "🎬 Starting nodes in sequence..."

# Start Camera Node
echo "📷 Starting Camera Node..."
ros2 run smart_cane_system camera_node > logs/camera.log 2>&1 &
CAMERA_PID=$!
sleep 2

# Check if camera started successfully
if ! kill -0 $CAMERA_PID 2>/dev/null; then
    echo "❌ Camera node failed to start! Check logs/camera.log"
    exit 1
fi
echo "   ✅ Camera node started (PID: $CAMERA_PID)"

# Start YOLO Detection Node  
echo "🧠 Starting YOLO Detection Node..."
ros2 run smart_cane_system yolo_detection_node > logs/yolo.log 2>&1 &
YOLO_PID=$!
sleep 3

if ! kill -0 $YOLO_PID 2>/dev/null; then
    echo "❌ YOLO node failed to start! Check logs/yolo.log"
    exit 1
fi
echo "   ✅ YOLO detection started (PID: $YOLO_PID)"

# Start Ultrasonic Node
echo "📡 Starting Ultrasonic Sensor Node..."
ros2 run smart_cane_system ultrasonic_node > logs/ultrasonic.log 2>&1 &
ULTRASONIC_PID=$!
sleep 2

if ! kill -0 $ULTRASONIC_PID 2>/dev/null; then
    echo "❌ Ultrasonic node failed to start! Check logs/ultrasonic.log"
    exit 1
fi
echo "   ✅ Ultrasonic sensor started (PID: $ULTRASONIC_PID)"

# Start Obstacle Fusion Node (The Brain!)
echo "⚙️  Starting Obstacle Fusion Node..."
ros2 run smart_cane_system obstacle_fusion_node > logs/fusion.log 2>&1 &
FUSION_PID=$!
sleep 2

if ! kill -0 $FUSION_PID 2>/dev/null; then
    echo "❌ Fusion node failed to start! Check logs/fusion.log"
    exit 1
fi
echo "   ✅ Obstacle fusion started (PID: $FUSION_PID)"

# Start Vibration Node
echo "📳 Starting Vibration Feedback Node..."
ros2 run smart_cane_system vibration_node > logs/vibration.log 2>&1 &
VIBRATION_PID=$!
sleep 2

if ! kill -0 $VIBRATION_PID 2>/dev/null; then
    echo "❌ Vibration node failed to start! Check logs/vibration.log"
    exit 1
fi
echo "   ✅ Vibration feedback started (PID: $VIBRATION_PID)"

# Start Speaker Node
echo "🔊 Starting Speaker Node..."
ros2 run smart_cane_system speaker_node > logs/speaker.log 2>&1 &
SPEAKER_PID=$!
sleep 2

if ! kill -0 $SPEAKER_PID 2>/dev/null; then
    echo "❌ Speaker node failed to start! Check logs/speaker.log"
    exit 1
fi
echo "   ✅ Speaker started (PID: $SPEAKER_PID)"

echo ""
echo "🎉 SMART CANE SYSTEM RUNNING!"
echo "=============================="
echo "📊 System Status:"
echo "   📷 Camera:           PID $CAMERA_PID"
echo "   🧠 YOLO Detection:   PID $YOLO_PID" 
echo "   📡 Ultrasonic:       PID $ULTRASONIC_PID"
echo "   ⚙️  Obstacle Fusion:  PID $FUSION_PID"
echo "   📳 Vibration:        PID $VIBRATION_PID"
echo "   🔊 Speaker:          PID $SPEAKER_PID"
echo ""
echo "🦯 Your Smart Cane is ready for navigation!"
echo "   • Point at objects to see detection boxes"
echo "   • Feel vibration patterns as you get closer:"
echo "     💙 Slow pulses:   Far objects (2-2.4m)"
echo "     🟡 Medium rhythm: Medium distance (1-2m)" 
echo "     🔴 Rapid buzzing: Close danger (<1m)"
echo ""
echo "🛑 Press Ctrl+C to stop all nodes and exit"
echo ""

# Monitor processes and keep script running
while true; do
    # Check if any critical process died
    for pid in $CAMERA_PID $YOLO_PID $ULTRASONIC_PID $FUSION_PID $VIBRATION_PID $SPEAKER_PID; do
        if ! kill -0 $pid 2>/dev/null; then
            echo "❌ A critical process crashed! Check logs/"
            cleanup
        fi
    done
    
    # Wait before next check
    sleep 5
done