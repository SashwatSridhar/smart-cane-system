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
    
    # Force kill any remaining processes
    pkill -f "camera_node.py"
    pkill -f "yolo_detection_node.py" 
    pkill -f "ultrasonic_node.py"
    pkill -f "obstacle_fusion"
    pkill -f "vibration_node.py"
    
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

echo "🎬 Starting nodes in sequence..."

# Start Camera Node
echo "📷 Starting Camera Node..."
python3 camera_node.py > logs/camera.log 2>&1 &
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
python3 yolo_detection_node.py > logs/yolo.log 2>&1 &
YOLO_PID=$!
sleep 3

if ! kill -0 $YOLO_PID 2>/dev/null; then
    echo "❌ YOLO node failed to start! Check logs/yolo.log"
    exit 1
fi
echo "   ✅ YOLO detection started (PID: $YOLO_PID)"

# Start Ultrasonic Node
echo "📡 Starting Ultrasonic Sensor Node..."
python3 ultrasonic_node.py > logs/ultrasonic.log 2>&1 &
ULTRASONIC_PID=$!
sleep 2

if ! kill -0 $ULTRASONIC_PID 2>/dev/null; then
    echo "❌ Ultrasonic node failed to start! Check logs/ultrasonic.log"
    exit 1
fi
echo "   ✅ Ultrasonic sensor started (PID: $ULTRASONIC_PID)"

# Start Obstacle Fusion Node (The Brain!)
echo "⚙️  Starting Obstacle Fusion Node..."
python3 obstacle_fusion.py > logs/fusion.log 2>&1 &
FUSION_PID=$!
sleep 2

if ! kill -0 $FUSION_PID 2>/dev/null; then
    echo "❌ Fusion node failed to start! Check logs/fusion.log"
    exit 1
fi
echo "   ✅ Obstacle fusion started (PID: $FUSION_PID)"

# Start Vibration Node
echo "📳 Starting Vibration Feedback Node..."
python3 vibration_node.py > logs/vibration.log 2>&1 &
VIBRATION_PID=$!
sleep 2

if ! kill -0 $VIBRATION_PID 2>/dev/null; then
    echo "❌ Vibration node failed to start! Check logs/vibration.log"
    exit 1
fi
echo "   ✅ Vibration feedback started (PID: $VIBRATION_PID)"

echo ""
echo "🎉 SMART CANE SYSTEM RUNNING!"
echo "=============================="
echo "📊 System Status:"
echo "   📷 Camera:           PID $CAMERA_PID"
echo "   🧠 YOLO Detection:   PID $YOLO_PID" 
echo "   📡 Ultrasonic:       PID $ULTRASONIC_PID"
echo "   ⚙️  Obstacle Fusion:  PID $FUSION_PID"
echo "   📳 Vibration:        PID $VIBRATION_PID"
echo ""
echo "📺 YOLO Detection Window should be open - you can see what the cane detects!"
echo ""
echo "🦯 Your Smart Cane is ready for navigation!"
echo "   • Point at objects to see detection boxes"
echo "   • Feel vibration patterns as you get closer:"
echo "     💙 Slow pulses:   Far objects (2-3m)"
echo "     🟡 Medium rhythm: Medium distance (1-2m)" 
echo "     🔴 Rapid buzzing: Close danger (<1m)"
echo ""
echo "🛑 Press Ctrl+C to stop all nodes and exit"
echo ""

# Monitor processes and keep script running
while true; do
    # Check if any critical process died
    if ! kill -0 $CAMERA_PID 2>/dev/null; then
        echo "❌ Camera node crashed! Check logs/camera.log"
        break
    fi
    
    if ! kill -0 $YOLO_PID 2>/dev/null; then
        echo "❌ YOLO node crashed! Check logs/yolo.log"
        break
    fi
    
    if ! kill -0 $ULTRASONIC_PID 2>/dev/null; then
        echo "❌ Ultrasonic node crashed! Check logs/ultrasonic.log"
        break
    fi
    
    if ! kill -0 $FUSION_PID 2>/dev/null; then
        echo "❌ Fusion node crashed! Check logs/fusion.log"
        break
    fi
    
    if ! kill -0 $VIBRATION_PID 2>/dev/null; then
        echo "❌ Vibration node crashed! Check logs/vibration.log"
        break
    fi
    
    # Wait before next check
    sleep 5
done

# If we get here, a process crashed
echo "🚨 A critical process crashed - stopping system"
cleanup