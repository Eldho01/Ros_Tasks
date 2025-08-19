#! /usr/bin/python3

import rclpy
from rclpy.node import Node

from example_interfaces.srv import AddTwoInts


class AddTwoInts_server(Node):
    def __init__(self):
        super().__init__("Add_Two_Ints")
        self.server = self.create_service(AddTwoInts, "the_addition_of_twoInts",
                                          self.callback_addition_of_TwoInts) # type of service, service name, callbackfnc,
        
        self.get_logger().info("Add_Two_Ints started...")
        
        
        
    def callback_addition_of_TwoInts(self, request, response):
        
        response.sum = request.a + request.b
        self.get_logger().info(f"sum of {request.a} and {request.b} = {response.sum}")
        return response
        
        
        
        
        
        
def main(args= None):
    rclpy.init(args= args)
    node = AddTwoInts_server()
    rclpy.spin(node)
    rclpy.shutdown()
    
if __name__ == "__main__":
    main()
    