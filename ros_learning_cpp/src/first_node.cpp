#include "rclcpp/rclcpp.hpp"

class FirstNode: public rclcpp::Node
{
public:
    FirstNode() : Node("first_node"), counter_(0)
    {
        RCLCPP_INFO(this->get_logger(), "Hello in CPP");
        timer_ = this->create_wall_timer(std::chrono::seconds(1),
                    std::bind(&FirstNode::timerCallback, this));
    }
private:
   void timerCallback(){
    counter_++;
    RCLCPP_INFO(this->get_logger(), "Running Timer for %dth time", counter_);
   } 
   rclcpp::TimerBase::SharedPtr timer_;
   int counter_;
};




int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    // auto node = rclcpp::Node::make_shared("first_node");
    // RCLCPP_INFO(node->get_logger(), "Hello in CPP");
    auto node = std::make_shared<FirstNode>();
    
    rclcpp::spin(node);

    rclcpp::shutdown();
    return 0;

}