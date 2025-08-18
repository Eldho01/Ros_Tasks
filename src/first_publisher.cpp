#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"

class First_num: public rclcpp::Node{
    public:
    First_num():Node("number_publisher"){
        publisher_ = this->create_publisher<std_msgs::msg::Int64>("number",10);
        timer_ = this->create_wall_timer(std::chrono::seconds(1),
                        std::bind(&First_num::publish_num,this));
        RCLCPP_INFO(this->get_logger(),"First publisher started...");

    }
    private:
    void publish_num(){
        auto msg = std_msgs::msg::Int64();
        msg.data = 10;
        publisher_->publish(msg);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::Int64>::SharedPtr publisher_;

};

int main(int argc, char **argv){
    rclcpp::init(argc,argv);
    auto node = std::make_shared<First_num>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    
    return 0;
}