#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"


class AddTwoIntsClient: public rclcpp::Node{

    public:
    AddTwoIntsClient():Node("Add_Two_Ints_client"){

        thread1_ = std::thread(std::bind(&AddTwoIntsClient::callAddTwoInstService, this,1, 7));  

        RCLCPP_INFO(this->get_logger(),"Add_Two_ints_client started...");
    }
    void callAddTwoInstService(int a, int b){
        auto client = this->create_client<example_interfaces::srv::AddTwoInts>("the_addition_of_twoInts");
        while(!client->wait_for_service(std::chrono::seconds(1))){

            RCLCPP_WARN(this->get_logger(), "waiting for the server...");
        }
        auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
        request->a = a;
        request->b = b;


        auto future = client->async_send_request(request);


        try{
            auto response = future.get();
            RCLCPP_INFO(this->get_logger(),"sum = %ld",response->sum);
        }
        catch(const std::exception &e){
            RCLCPP_ERROR(this->get_logger(),"Service call failed...");
        }
    }
    private:
    
    std::thread thread1_;

};
 


int main(int argc, char **argv){

    rclcpp::init(argc, argv);

    /*
    auto node = std::make_shared<rclcpp::Node>("Add_Two_Ints_client");
    auto client = node->create_client<example_interfaces::srv::AddTwoInts>("the_addition_of_twoInts");
    while(!client->wait_for_service(std::chrono::seconds(1))){

        RCLCPP_WARN(node->get_logger(), "waiting for the server...");
    }
    auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
    request->a = 10;
    request->b = 11;

    auto future = client->async_send_request(request);
    if (rclcpp::spin_until_future_complete(node, future)==rclcpp::FutureReturnCode::SUCCESS){
        RCLCPP_INFO (node->get_logger(), "sum : %ld",future.get()->sum);
    }
    else{
        RCLCPP_ERROR(node->get_logger()," Error while handling service...");
    }
    */
    auto node = std::make_shared<AddTwoIntsClient>();
    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}