#! /usr/bin python3
import rclpy
from rclpy.node import Node

from example_interfaces.msg import String

class SmartphoneSubscriber(Node):
    def __init__(self):
        super().__init__("Smartphone")
        
        self.subscriber_ = self.create_subscription(String,
                                    "news_station_pub", self.callback_news_pub,10)
        self.get_logger().info("Smartphone node started...")
        
    def callback_news_pub(self,msg):
        self.get_logger().info(msg.data)
        
        
def main(args= None):
    
    rclpy.init(args= args)
    node = SmartphoneSubscriber()
    rclpy.spin(node)
    rclpy.shutdown()
    
if __name__ == "main":
    main()

