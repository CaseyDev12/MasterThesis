#ifndef UR10CONTROLLER_HPP_
#define UR10CONTROLLER_HPP_


#include <ros/ros.h>
#include <ur10_utils/utils.h>
#include <iostream>
#include <fstream>
#include <ur10_utils/Data.h>
#include <ur10_utils/Reference.h>		
#include <ros/package.h>	
#include <ur10_lib/UR10k.h>
#include <stdio.h>
#include <ur10_lib/UR10Planner.h>

using namespace std;

#define _USE_MATH_DEFINES
#include<math.h>
#include <time.h>
#include <chrono>

#include "RobotController.h"
#include "HumanRobotController.h"
#include "ComauInteraction.h"
#include "Filter.h"


#define UR10_SAMPLE_TIME 0.008
#define UR10_DOFS 6
#define UR10_JOINTS 6
#define UR10_NAME_LOG "UR10"
#define N_FT 6
#define N_X 6
#define MAX_DX {2.16, 2.16, 3.15, 3.2, 3.2, 3.2}
#define MAX_DDX {0.05, 0.05, 0.05, 0.05, 0.05, 0.05}
#define CHECK_SKEL TRUE
#define TRAJ_PRE_SKELETON TRUE
#define WAIT 10
#define TIME_FINAL_TRAJ_OPER_SPACE 10
#define TIMEOUT_DETECTION 40


/* 
*  La classe UR10Controller, in particolare la Callback gestisce tutta la logica di movimentazione dell'UR10.
*  Il robot può trovarsi in 4 stati diversi:
*  - nel primo (in cui si entra quando parte il software o quando una persona viene persa), è prevista l'esecuzione di
*    una traiettoria spazio giunti per portarsi in una posizione desiderata comoda per iniziare la ricerca di una persona
*  - nel secondo stato in cui si entra una volta terminata la traiettoria del primo stato, si alternano due fasi, una in cui il robot 
*    è fermo e si aspetta che una persona venga identificata e una in cui il robot esegue una traiettoria nello spazio operativo per 
*    inquadrare una nuova parte di cella. (Per le traiettorie spazio operativo si cicla su una serie di punti prestabiliti).
*  - nel terzo stato si entra invece non appena viene individuata una persona. Viene utilizzata la classe HumanRobotController per
*    il calcolo della nuova posizione desiderata per l'ee dell'UR10, la quale viene poi invertita
*  - Nel quarto stato si entra quando una persona viene persa e prima di eseguire la traiettoria spazio giunti del primo stato. 
*    Prevede che il robot stia fermo 
*/

class UR10Controller: public RobotController{

private:
	double qd[UR10_JOINTS]; //Joints speeds desired
	double dqd[UR10_JOINTS]; //Joints speeds desired
	double xd[UR10_DOFS]; //Positions desired
	double dxd[UR10_DOFS]; //Speeds desired
	double ddxd[UR10_DOFS]; //Accelerations desired
	UR10k* kin;    // Oggetto per la cinematica diretta e inversa
	UR10Planner* planner;  // Oggetto per la pianificazione di traiettorie 
	double ddqd[UR10_JOINTS];  // Accelerazioni ai giunti desiderate
	vector<double> max_dx;
  	vector<double> max_ddx;
  	vector<bool>   selection_vec;
	bool robot_ready;    // Variabile di controllo per sapere se le posizioni lette da topic sono da scartare o meno a seconda quindi se il robot è in fase di inizializzazione o meno
	int id_packet=0;   // Id pacchetto inviato al nodo socket
	double Acid_c[4][4]; // Matrice di roto-traslazione tra terna camera identificata e terna camera in cui vengono lette le coordinate
	double x[UR10_DOFS]; // Posizioni spazio operativo effettive
	double eul_fin[3]; // orientamento desiderato per l'ee mentre insegue una persona
	time_t theTime = time(NULL); // tempo attuale per salvataggio su file
	int day; // giorno attuale
	int month; // mese attuale
	int year; // anno attuale
	int hour; // ora attuale
	int min; // minuti attuali
	bool traj_joints_space = true; // variabile che indica se eseguire una traiettoria iniziale spazio giunti
	double joints_des_init[6]; // valori ai giunti desiderati all'inizio per la traiettoria spazio giunti
	HumanRobotController* humanRobot; // oggetto della classe per l'interazione uomo robot
	double dq0[6] = {0, 0, 0, 0, 0, 0}; // vettore di velocità ai giunti nulle
	bool end_traj = true; // variabile che controlla se siamo arrivati in un punto di via
	double wait_time = 0; // variabile che conta il tempo trascorso dall'ee in ciascun punto di via (10 sec)
	int index_traj_pre_skeleton = 0; // indice riguardante l'ultimo punto di via desiderato
	double points_traj_pre_skeleton[4][6]; // Matrice contenente i punti di via (spazio oper) per la fase di ricerca dello human
	bool init_new_traj = false; // variabile che definisce se inizializzare l'inversione con una nuova traiettoria
	double traj_time = 0; // tiene traccia del tempo passato dall'inizio di ogni traiettoria da invertire durante la ricerca dello human
	double count = 0; // utilizzato per la sinusoide commentata
	double x_fin[6]; // posizione + orientamento desiderati per l'ee mentre insegue una persona
	double pos_des[3]; // posizione desiderata per l'ee mentre insegue una persona
	bool follow_human = false; // variabile di controllo che indicase l'ur10 sta seguendo una persona
	bool ik = false; // variabile di controllo che indica se siamo in fase di inversione o meno
	double deltaPos[3]; // delta in posizione da inviare ai comau
	double deltaVel[3]; // delta in velocità da inviare ai comau
	double deltaAcc[3]; // delta in accelerazione da inviare ai comau
	double pos_hand[3]; // posizione della mano destra della persona
	ComauInteraction * comau_inter; // oggetto della classe di interazione col comau, che permette di calcolare il delta sul task 
	double qd_prec[6]; // posizione ai giunti desiderata al passo precedente, aggiornata solo quando una persona viene persa
	bool stop_robot = false; // variabile di controllo che dice di fermarmi quando una persona viene persa
	Filter * filter_stop_traj; // filtro che serve a fermarmi in modo dolce quando una persona viene persa
	double timeout_research = 0; // variabile che tiene conto del tempo trascorso da quando una persona è stata persa
	ros::Publisher  comau_pub; // topic su cui pubblico il delta sul task per i robot comau
	ros::Subscriber comau_sub; // topic a cui mi sottoscrivo per leggere la posizione dell'oggetto trasportato dai comau
	double pos_obj_comau[3]; // posizione dell'oggetto ricevuta dal robot comau con cui si ha la comunicazione
	double f[3]; // forze generate sulla base della distanza tra l'oggetto e la mano destra della persona
	bool error_joint = false; // variabile di controllo sull'errore dei giunti (non usata per ora)

public: 
	UR10Controller(ros::NodeHandle& n,string topic_pub, string topic_sub,string ft_sensor_topic_sub,const string& log_path, bool log_enabled,bool debug_enabled);
	~UR10Controller();

private:	
	/* 
	* Nel caso di traiettoria spazio giunti calcola le prossime posizioni ai giunti desiderate tramite pianificazione
	* Nel caso di traiettoria spazio operativo calcola la prossima posizione e il prossimo orientamento desiderati e poi
	* li inverte per calcolare le posizioni ai giunti relative desiderate
	*/
	void updateControlInput(); 
	
	/* 
	* Callback relativa alla lettura da topic delle posizioni ai giunti dell'ur10
	* Quando questa viene richiamata il programma procede nel suo funzionamento. Viene richiamata ogni 0.008 s
	*/
	void robotJointStateCallback(const ur10_utils::Reference::ConstPtr& msg);

	/*  
	* Callback relativa alla lettura da topic delle posizioni dell'"oggetto" trasportato dai comau 
	*/
	void comauJointStateCallback(const comau_coop_utils::Data& msg);

	/*
	* Se non si trova una persona entro TIMEOUT_DETECTION secondi da quando si è persa la precedente allora si fa il reset del programma 		*/
	void reset_program();

	double norm(double a[6], double b[6]);
	double computeJointsDistances(double qr[6], double q[6]);
	void scriviFile(string file, double var[], int n);

};

#endif
