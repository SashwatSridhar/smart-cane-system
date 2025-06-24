#!/bin/bash

echo "🎧 BLUETOOTH AUDIO QUALITY FIX"
echo "==============================="
echo

# Check current Bluetooth audio codec
echo "📊 Current Bluetooth audio codec:"
pactl list short sinks | grep bluez

echo
echo "🔄 Switching to high-quality A2DP codec..."

# Get the Bluetooth card number
BT_CARD=$(pactl list cards short | grep bluez | cut -f1)

if [ -n "$BT_CARD" ]; then
    echo "   Found Bluetooth card: $BT_CARD"
    
    # Switch to high-quality A2DP profile
    pactl set-card-profile $BT_CARD a2dp_sink
    
    echo "✅ Switched to A2DP high-quality audio"
    echo
    
    # Set as default sink
    BT_SINK=$(pactl list short sinks | grep bluez | grep a2dp | cut -f2)
    if [ -n "$BT_SINK" ]; then
        pactl set-default-sink $BT_SINK
        echo "🎯 Set as default audio device"
    fi
    
    # Increase volume to optimal level
    pactl set-sink-volume @DEFAULT_SINK@ 85%
    echo "🔊 Set volume to 85%"
    
else
    echo "❌ No Bluetooth audio device found"
    echo "   Make sure your headphones are connected"
fi

echo
echo "🧪 Testing audio quality..."
echo "You should hear clear speech:"

# Test with better TTS settings
python3 - << EOF
import pyttsx3
import time

try:
    engine = pyttsx3.init()
    
    # Get all available voices
    voices = engine.getProperty('voices')
    print(f"Available voices: {len(voices)}")
    
    for i, voice in enumerate(voices[:3]):  # Test first 3 voices
        print(f"Testing voice {i+1}: {voice.name}")
        
        engine.setProperty('voice', voice.id)
        engine.setProperty('rate', 150)     # Slower for clarity
        engine.setProperty('volume', 1.0)   # Max volume
        
        engine.say(f"Testing voice {i+1}. The chair is 1.5 meters away.")
        engine.runAndWait()
        time.sleep(1)
        
    print("✅ Audio test complete!")
    
except Exception as e:
    print(f"❌ TTS test failed: {e}")
EOF

echo
echo "🏁 Bluetooth audio fix complete!"
echo "If audio is still muffled, try Fix 2..."