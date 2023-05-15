#include "ros/ros.h"
#include "nae_vision/GroundingCheck.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "vision_client");

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<nae_vision::GroundingCheck>("grounding_check");
  nae_vision::GroundingCheck srv;
  srv.request = {};

  if (client.call(srv))
  {
    bool status;
    status = srv.response.result;
    if (status == true)
    {
      ROS_INFO("Table can be cleaned.");
    }
    else
    {
      ROS_INFO("Table is occupied!");
    }
  }
  else
  {
    ROS_ERROR("Failed to call service");
    return 1;
  }
  return 0;
}
