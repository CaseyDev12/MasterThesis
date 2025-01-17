#include <ros/ros.h>		
#include <ros/package.h>
#include <iostream>
#define TOSTRING(x) #x

#include "UR10Controller.h"
#include <armadillo>

using namespace arma;


int main(int argc, char **argv)
{
	ros::init(argc, argv, TOSTRING(NAMECOMPONENT));
	ros::NodeHandle n;
	
	bool ur10_debug;
	bool ur10_log;
	string ur10_pub_topic_name, ur10_sub_topic_name,ur10_ft_sensor_sub_topic_name;
	
	//Read the config paramaters stored in config/config.yaml
	if (n.getParam("ur10_debug", ur10_debug)) {
		if(ur10_debug==true)
			ROS_INFO("Got param 'debug' ur10 true");
		else 
			ROS_INFO("Got param 'debug' ur10 false");
	
    		//ROS_INFO("Got param 'debug' comau and ur10: %d %d", comau_debug==true, ur10_debug);
    }else{
	    ROS_ERROR("Cannot retrieve one or both 'debug' params. Exit");
	    ros::shutdown();
	}

	if(ur10_debug){		
		if(ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME, ros::console::levels::Debug)){
			ros::console::notifyLoggerLevelsChanged();
		}
	}
	if (n.getParam("ur10_log", ur10_log)) {
    		//ROS_INFO("Got param 'log' comau and ur10: %d %d", comau_log, ur10_log);
		if(ur10_log==true)
			ROS_INFO("Got param 'log' ur10 true");
		else 
			ROS_INFO("Got param 'log' ur10 false");
   }else{
	    ROS_ERROR("Cannot retrieve one or both 'log' params. Exit");
	    ros::shutdown();
	}

	if (n.getParam("ur10_pub_topic_name", ur10_pub_topic_name) && n.getParam("ur10_sub_topic_name", ur10_sub_topic_name) ) {
    		ROS_INFO("Got param 'pub_topic' and 'sub_topic' ur10: %s %s", ur10_pub_topic_name.c_str(), ur10_sub_topic_name.c_str());
    	}else{
	    	ROS_ERROR("Cannot retrieve one or both 'pub_topic' and 'sub_topic' ur10 params. Exit");
	    	ros::shutdown();
	}
	

	string package_path = "/home/ros-account/catkin_ws/src/Tesi/Sorrentino";
  	string log_path    = package_path + "/log/";
	UR10Controller ur10Contr(n,ur10_pub_topic_name, ur10_sub_topic_name,ur10_ft_sensor_sub_topic_name,log_path,ur10_log,ur10_debug);
	ros::spin();

  	return 0;
}
