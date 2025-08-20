import rclpy
from rclpy.node import Node

from my_sensor_interfaces.msg import HardwareStatus


class HardwarePublisher(Node): 
    def __init__(self):
        super().__init__("hwStatus_pub")
        self.publiser_ = self.create_publisher(HardwareStatus,"status_rob", 10)
        self.timer_ = self.create_timer(1, self.robot_hw_pub)
        self.get_logger().info("hwStatus_pub started...")
        
    def robot_hw_pub(self):
        msg = HardwareStatus()
        msg.temperature = 30
        msg.are_motor_ready = True
        msg.debug_msg = "status updated."
        
        self.publiser_.publish(msg)
        
        
        
        
        
def main(args=None):
    rclpy.init(args = args)
    
    node = HardwarePublisher()
    rclpy.spin(node)
    rclpy.shutdown()
    
if __name__ == "__main__":
    main()
