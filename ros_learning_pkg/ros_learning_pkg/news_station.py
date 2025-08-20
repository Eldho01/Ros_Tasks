import rclpy
from rclpy.node import Node
from example_interfaces.msg import String
class NewStation(Node):
    def __init__(self):
        super().__init__("news_station") 
        self.declare_parameter("message_to_publish", "hello") # <parameter name>, <default value>
        self.declare_parameter("publish_interval", 1.0)
        
        self.msgData_ = self.get_parameter("message_to_publish").value
        self.interval_ = self.get_parameter("publish_interval").value
        
        self.publiser_ = self.create_publisher(String, "news_station_pub",10 ) # msg datatype, topic name, queue length
        self.timer_ = self.create_timer(self.interval_,self.publish_news)
        self.get_logger().info("news_station started...")
        
        
    def publish_news(self):
        msg = String()
        msg.data = self.msgData_
        self.publiser_.publish(msg)



def main(args=None):
    rclpy.init(args=args)
    node = NewStation()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == 'main':
    main()