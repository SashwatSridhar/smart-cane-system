"""
Create the node
create a subscriber topic that subs to the /obstacle_alert
create a callback for the subscriber -> Takes the msg and it and based on the message it makes the vibrations accordingly
"""


#imports
#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import RPi.GPIO as GPIO
import time
import threading



class Vibration(Node):
    def __init__(self):
        super().__init__('vibration_node')

        
        # GPIO Setup
        GPIO.setmode(GPIO.BCM)
        GPIO.setup(18, GPIO.OUT)
        GPIO.output(18, GPIO.LOW)



        #structure of creating subscribers
        '''
            self.subscriber_name = self.create_subscription(
            MessageType,           # What type of message
            '/topic_name',         # Which topic to listen to  
            self.callback_function, # What function to call when message arrives
            10                     # Queue size (usually 10 is fine)
        )
            ''' 

        self.vibration_alert_listener = self.create_subscription(
            String,
            '/obstacle_alert',
            self.vibration_callback,
            10
        )  

        self.get_logger().info('Vibration Node initialized')

    def vibration_callback(self, msg):
        if msg.data == 'Fast':
            self.vib_fast()

        if msg.data == 'Medium':
            self.vib_medium()

        if msg.data == 'Slow':
            self.vib_slow()

    def vib_fast(self):
        """Fast vibration"""
        threading.Thread(target=self.vibrate_pattern, args=(0.1, 0.1, 10)).start() #0.1 is the on time for vibrate, 0.1 is the off time to stop, 10 is the cycles or the number of times 

    def vib_medium(self):
        """Medium vibration"""
        threading.Thread(target=self.vibrate_pattern, args=(0.2, 0.2, 6)).start()

    def vib_slow(self):
        """Slow vibration"""
        threading.Thread(target=self.vibrate_pattern, args=(0.4, 0.4, 4)).start()

    def vibrate_pattern(self, on_time, off_time, cycles):
        """Execute vibration pattern"""
        for _ in range(cycles):
            GPIO.output(18, GPIO.HIGH)
            time.sleep(on_time)
            GPIO.output(18, GPIO.LOW)
            time.sleep(off_time)

    def destroy_node(self):
        GPIO.cleanup()
        super().destroy_node()


def main(args=None):
    # TODO: Initialize ROS2
    rclpy.init(args = args)
    # TODO: Create your node
    node = Vibration()
    # TODO: Spin the node (keep it running)
    rclpy.spin(node)
    # TODO: Cleanup when done
    rclpy.shutdown()

if __name__ == '__main__':
    main()
                