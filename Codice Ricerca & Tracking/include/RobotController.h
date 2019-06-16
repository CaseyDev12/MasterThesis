#ifndef ROBOTCONTROLLER_HPP_
#define ROBOTCONTROLLER_HPP_


#include <ros/ros.h>
#include <ros/package.h>
#include <time.h>
#include <ur10_utils/utils.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <ur10_utils/Data.h>
#include <ur10_utils/Reference.h>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>	
#include <comau_coop_utils/Data.h>
#include <comau_coop_utils/Reference.h> 	

#include <armadillo>

using namespace std;
using namespace arma;

class RobotController{

protected:
	double q0[6];
	double qr[6];
	double dqr[6];
	double qd[6];
	double dqd[6];
	bool  first_msg = true;
	float robot_time = 0.0;
	int dofs;
	float step_time;
	ros::Publisher  robot_pub;
	ros::Subscriber robot_sub;
	
	bool debug_enabled;

	int iterations;
	int freq_log;//if =1 each time that updateLog is called, the log file is written
	string log_path;
	bool log_enabled;
	ostringstream to_save_curr,to_save; 
	ofstream log_file;
	ros::Time curr_time;
public: 
	//template <class SUB_MSG>

	RobotController(int dofs, float step_time,const string& log_path="",const string& name_log_file="", bool log_enabled=false,bool debug_enabled=true,int freq_save=10);
	//virtual void robotJointStateCallback(const sensor_msgs::JointState::ConstPtr& msg);
	virtual void updateControlInput(void) =0;
protected: 
	~RobotController();
	void updateLog(void);
	void saveVector(double v[],int size);
	void saveVector(fcolvec v);
	void saveScalar(double val);

};
/*
template <class SUB_MSG>
RobotController::RobotController(ros::NodeHandle& n,string topic_pub, string topic_sub,int dofs, float step_time){
	robot_sub = n.subscribe<SUB_MSG>(topic_sub, 1000, &RobotController::robotJointStateCallback,this);
	
	this->dofs=dofs;
	this->step_time=step_time;
}*/
#endif
