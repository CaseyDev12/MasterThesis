#include <RobotController.h>


RobotController::RobotController(int dofs, float step_time,const string& base_log_path,const string& name_log_file,bool log_enabled,bool debug_enabled,int freq_save){
	this->dofs=dofs;
	this->step_time=step_time;
	this->log_enabled=log_enabled;
	this->debug_enabled=debug_enabled;
	
	if(log_enabled){
		//Get current time and date
		time_t rawtime;
	 	time(&rawtime);
		struct tm * timeinfo;
	  	char buffer[30];
		timeinfo = localtime(&rawtime);
		strftime(buffer,sizeof(buffer),"%d_%m_%Y-%I_%M_%S_",timeinfo);
		//Create log path
		ostringstream oss;
		oss << base_log_path ;
	    	oss << buffer;
	    	oss << name_log_file <<".txt";
	    	this->log_path = oss.str();	
		//Open log file 
		ROS_INFO("ROBOT CONTROLLER: path %s",log_path.c_str());
	  	log_file.open(log_path, ofstream::out | ofstream::app);
		if(!log_file.is_open()){
			ROS_ERROR("Error opening log file");
			ros::shutdown();
		}
		this->freq_log=freq_save;
		iterations=1;
	}
}

RobotController::~RobotController(){
	if(log_enabled && log_file.is_open()){
		log_file.close();
	}
}
void RobotController::updateLog(void){
	//
	if(to_save_curr.tellp() > 0){ //to check if put || to_save.tellp() >0
		//Put the current time as first element of the new row
		curr_time=ros::Time::now();
		char temp[30];
		sprintf(temp,"%f",curr_time.toSec());
		to_save << temp << " ";
		to_save << to_save_curr.str() << endl;
		//ROS_INFO("to_save_curr: %s",to_save_curr.str().c_str());
		to_save_curr.clear();
		to_save_curr.str("");
		if(iterations==freq_log){		
			//ROS_INFO("to_save \n%s",to_save.str().c_str());
			log_file << to_save.str();
			to_save.clear();
			to_save.str("");
			iterations=1;
		}else{
			iterations++;
		}
	}
}

void RobotController::saveVector(double v[],int size){
	for(int i=0;i<size;i++){
		to_save_curr<<v[i]<<" ";
	}
}

void RobotController::saveVector(fcolvec v){	
	for(int i=0;i<v.size();i++){
		to_save_curr<<v[i]<<" ";
	}
	
}

void RobotController::saveScalar(double val){
	to_save_curr<<val;
}

