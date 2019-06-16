#ifndef HUMANROBOTCONTROLLER_HPP_
#define HUMANROBOTCONTROLLER_HPP_


#include "Filter.h"
#include <ros/ros.h>
#include <tf/tf.h>
#include <tf/transform_listener.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>
#include<vector>
#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;


/*
* La classe si occupa della lettura dal topic /tf delle posizioni della persona (se questa è stata identificata altrimenti viene 
* lanciata un'eccezione) e del calcolo della nuova posizione e orientamento desiderati per l'ee dell'UR10.
* Si occupa anche di filtrare le posizioni desiderate per l'ee prima di restituirle alla classe UR10Controller
*/


class HumanRobotController {


private:
	double Acid_c[4][4];
	double ur10_sample_time;
	double max_delta_phi;
	Filter * filter_orient = NULL;
	Filter * filter_position = NULL;
	Filter * filter_head = NULL;
	Filter * filter_right_hand = NULL;
	time_t theTime = time(NULL);
	int day;
	int month;
	int year;
	int hour;
	int min;
	tf::TransformListener listener;
	tf::StampedTransform transform_right_hand; // Transform relativo alla mano destra
	tf::StampedTransform transform_head; // Transform relativo alla testa
	tf::StampedTransform transform_id; // Transform relativo all'id
	double eul_fin_pre[3];
	double sample_time_camera = 0;
	double last_pos[3];
	double old_sample[6];
	int count = 0;
	double b_mondo[3];
	int id_user = 0;
	std::vector<int> id_rejected;
	bool id_used = false;
	string frame_head = "";
	string frame_right_hand = "";
	double pos_right_hand[3];


public:
	bool human_first;	
	bool lost_human;
	bool ik = true;


public:
	HumanRobotController(double Acid_c[4][4], double ur10_sample_time, double max_delta_phi, double b_mondo[3]);
	~HumanRobotController();
	void skeletonPose(double x[6], double eul_final_des[3], double pos_des[3], double pos_hand[3]);
	void computeNextDesiredPoint(double x[6], double x_fin[6], double xd[6], double dxd[6]);
	void clearFilter();


private:
	void computeAb_cid(double Ab_cid[4][4], double x[6]);
	void computeRb_cid(double Rb_cid[3][3], double Ab_cid[4][4]);
	void computeAbc(double Abc[4][4], double Ab_cid[4][4]);
	void changeFrame(double A[4][4], double x[3], double x_new_frame[3]);	
	void writeLog(string file, double var[], int n);
	void computeDesiredPosition(double x_torso_mondo[3], double c_mondo[3], double pos_des[3]);
	void cross_product(double xc[], double zbc[], double nc[]);
	double computeNorm(double x[]);
	void computeDesiredOrient(const double human_actual[3], const double Rbc[3][3], const double eul_prec[3], double eul_des[3]);

};

#endif
