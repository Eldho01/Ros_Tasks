import rclpy
from rclpy.node import Node
from example_interfaces.msg import String
class NewStation(Node):
    def __init__(self):
        super().__init__("news_station") 
        self.publiser_ = self.create_publisher(String, "news_station_pub",10 ) # msg datatype, topic name, queue length
        self.timer_ = self.create_timer(1,self.publish_news)
        self.get_logger().info("news_station started...")
        

    def publish_news(self):
        msg = String()
        msg.data = "Hello"
        self.publiser_.publish(msg)



def main(args=None):
    rclpy.init(args=args)
    node = NewStation()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == 'main':
    main()