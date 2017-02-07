#include "ros/ros.h"
#include <std_msgs/String.h>
#include <gazebo_msgs/LinkStates.h>

#include <string>

class DataHandler
{
private:
    ros::NodeHandle nh;
    ros::Publisher pub;
public:
    DataHandler()
    {
        pub = nh.advertise<std_msgs::String>("test2",10);
    }
    
    void callback(const gazebo_msgs::LinkStates& msg)
    {
        pub.publish(std_msgs::String());
    }
};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "listener");
    ros::NodeHandle nh;
    
    DataHandler callbacks;
    ros::Subscriber sub = nh.subscribe("test1",1,&DataHandler::callback,&callbacks);
    
    ros::spin();
    
    return 0;
}
