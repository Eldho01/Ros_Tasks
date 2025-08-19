#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

class NewsStation:public rclcpp::Node{
    public:
    NewsStation():Node("News_Station"){
        publisher_ = this->create_publisher<example_interfaces::msg::String>("news_station_pub",10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(500),
                std::bind(&NewsStation::publish_news,this));
        RCLCPP_INFO(this->get_logger(),"News Node started...");


    }
    private:
    void publish_news(){
        auto msg = example_interfaces::msg::String();
        msg.data = std::string("hi, new news");
        publisher_->publish(msg);
    }
    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NewsStation>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;

}