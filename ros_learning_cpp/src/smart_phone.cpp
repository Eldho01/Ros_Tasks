#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

class SmartphoneSubscriber:public rclcpp::Node{
    public:
    SmartphoneSubscriber():Node("Smartphone"){
        subscriber_ = this->create_subscription<example_interfaces::msg::String>("news_station_pub",10,
                        std::bind(&SmartphoneSubscriber::callback_msg_news,this,
                        std::placeholders::_1));
        RCLCPP_INFO(this->get_logger(),"Smartphone node started...");

    }
    private:
    
    void callback_msg_news(const example_interfaces::msg::String::SharedPtr msg){
        RCLCPP_INFO(this->get_logger(),"%s",msg->data.c_str());
    }
    rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr subscriber_;
};

int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SmartphoneSubscriber>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}