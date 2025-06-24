#!/usr/bin/env python3

from gpiozero import OutputDevice
import time

# GPIO Setup for Pi 5 with gpiozero
motor = OutputDevice(23)  # Pin 16 = GPIO 23

print("gpiozero Motor Test (Pi 5 + Ubuntu)")
print("====================================")
print("GPIO 23 (Pin 16) controlling vibration motor")
print("")

try:
    # Test 1: Basic on/off
    print("Test 1: Motor ON for 2 seconds...")
    motor.on()
    time.sleep(2)
    motor.off()
    print("Motor OFF")
    time.sleep(1)
    
    # Test 2: Fast pattern
    print("Test 2: Fast vibration pattern...")
    for i in range(5):
        motor.on()
        time.sleep(0.1)
        motor.off()
        time.sleep(0.1)
    print("Fast pattern complete")
    time.sleep(1)
    
    # Test 3: Slow pattern  
    print("Test 3: Slow vibration pattern...")
    for i in range(3):
        motor.on()
        time.sleep(0.5)
        motor.off()
        time.sleep(0.5)
    print("Slow pattern complete")
    
    # Interactive mode
    print("\nInteractive Mode:")
    print("Press 1 = Motor ON, 0 = Motor OFF, q = Quit")
    
    while True:
        user_input = input("Enter command (1/0/q): ").strip().lower()
        
        if user_input == '1':
            motor.on()
            print("Motor ON")
        elif user_input == '0':
            motor.off()
            print("Motor OFF")
        elif user_input == 'q':
            print("Exiting...")
            break
        else:
            print("Invalid input. Use 1, 0, or q")

except KeyboardInterrupt:
    print("\nTest interrupted by user")

finally:
    # Cleanup
    motor.off()
    print("Motor turned off - cleanup complete")