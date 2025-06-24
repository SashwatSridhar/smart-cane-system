#!/usr/bin/env python3

from gpiozero import DistanceSensor
import time
import statistics

print("🔧 ULTRASONIC SENSOR DIAGNOSTIC TEST")
print("=====================================")
print("Testing HC-SR04 sensor range and reliability")
print("")

# Configure sensor
try:
    sensor = DistanceSensor(echo=24, trigger=18, max_distance=4)  # Set max distance explicitly
    print("✅ Sensor configured: Trigger=GPIO18, Echo=GPIO24")
except Exception as e:
    print(f"❌ Sensor setup failed: {e}")
    exit(1)

def test_basic_readings():
    print("📊 Test 1: Basic Distance Readings")
    print("-" * 40)
    
    readings = []
    for i in range(20):
        try:
            distance = sensor.distance
            readings.append(distance)
            print(f"Reading {i+1:2d}: {distance:.3f}m")
            time.sleep(0.5)
        except Exception as e:
            print(f"Reading {i+1:2d}: ERROR - {e}")
        
    if readings:
        avg = statistics.mean(readings)
        max_dist = max(readings)
        min_dist = min(readings)
        print(f"\n📈 Statistics:")
        print(f"   Average: {avg:.3f}m")
        print(f"   Maximum: {max_dist:.3f}m")
        print(f"   Minimum: {min_dist:.3f}m")
        print(f"   Range: {min_dist:.3f}m - {max_dist:.3f}m")
        return max_dist
    return 0

def test_distance_sweep():
    print("\n📏 Test 2: Manual Distance Verification")
    print("-" * 40)
    print("Move an object to different distances and press Enter:")
    
    distances = ["20cm", "50cm", "1m", "1.5m", "2m", "3m", "4m"]
    
    for target_dist in distances:
        input(f"\n🎯 Place object at ~{target_dist}, then press Enter...")
        
        # Take 5 readings
        readings = []
        for i in range(5):
            try:
                distance = sensor.distance
                readings.append(distance)
                print(f"  Reading {i+1}: {distance:.3f}m")
                time.sleep(0.2)
            except Exception as e:
                print(f"  Reading {i+1}: ERROR - {e}")
        
        if readings:
            avg = statistics.mean(readings)
            print(f"  ➡️  Average: {avg:.3f}m (Target: {target_dist})")

def test_continuous_monitoring():
    print("\n⏱️  Test 3: Continuous Monitoring")
    print("-" * 40)
    print("Monitoring sensor for 30 seconds. Move objects around...")
    print("Press Ctrl+C to stop early")
    
    try:
        start_time = time.time()
        max_detected = 0
        
        while time.time() - start_time < 30:
            try:
                distance = sensor.distance
                if distance > max_detected:
                    max_detected = distance
                
                # Only print significant changes
                print(f"Distance: {distance:.3f}m (Max so far: {max_detected:.3f}m)", end='\r')
                time.sleep(0.1)
                
            except Exception as e:
                print(f"Error: {e}")
                
        print(f"\n🏆 Maximum distance detected: {max_detected:.3f}m")
        return max_detected
        
    except KeyboardInterrupt:
        print(f"\n⏹️  Test stopped. Maximum detected: {max_detected:.3f}m")
        return max_detected

def diagnose_issues(max_range):
    print(f"\n🔍 DIAGNOSIS")
    print("=" * 40)
    
    if max_range < 0.5:
        print("❌ CRITICAL: Very short range (<50cm)")
        print("   Possible causes:")
        print("   - Wiring issues (check connections)")
        print("   - Power supply problems (HC-SR04 needs 5V)")
        print("   - Faulty sensor")
        
    elif max_range < 1.0:
        print("⚠️  WARNING: Limited range (<1m)")
        print("   Possible causes:")
        print("   - Insufficient power (check 5V supply)")
        print("   - Environmental interference")
        print("   - Sensor mounting angle")
        
    elif max_range < 2.0:
        print("🟡 CAUTION: Reduced range (<2m)")
        print("   Possible causes:")
        print("   - Timeout settings in gpiozero")
        print("   - Surface reflectivity issues")
        print("   - Temperature/humidity effects")
        
    else:
        print("✅ GOOD: Normal range (>2m)")
        print("   Sensor appears to be working correctly")
    
    print(f"\n💡 RECOMMENDATIONS:")
    print("   1. Ensure HC-SR04 has 5V power (not 3.3V)")
    print("   2. Check all wiring connections")
    print("   3. Test with large flat surfaces (wall, book)")
    print("   4. Avoid soft/angled surfaces that absorb sound")
    print("   5. Keep sensor level and perpendicular to target")

# Main test sequence
try:
    max_range1 = test_basic_readings()
    test_distance_sweep()
    max_range2 = test_continuous_monitoring()
    
    final_max = max(max_range1, max_range2)
    diagnose_issues(final_max)
    
finally:
    print(f"\n🏁 Test complete!")