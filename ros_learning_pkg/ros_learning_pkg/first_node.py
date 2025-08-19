#! /usr/bin/env python3
import rclpy
from rclpy.node import Node

class FirstNode(Node):
    def __init__(self):

        super().__init__("first") # initialize the node with the name "first"
        self.get_logger().info("Hello, ROS2!") # log a message to the console
        self.create_timer(1.0, self.timer_callback) # create a timer that calls timer_callback every 1 second
        self.counter = 0 # initialize a counter

    def timer_callback(self):
        self.counter += 1
        self.get_logger().info(f"Timer callback executed {self.counter} times")

def main(args=None):
    rclpy.init(args=args) # initialize the ROS2 communication
    # node = Node("first")
    # node.get_logger().info("Hello, ROS2!") # Hello workld in ROS2


    node = FirstNode() # create an instance of the FirstNode class
    rclpy.spin(node)
    rclpy.shutdown() # shutdown the ROS2 communication


if __name__ == '__main__':
    main()