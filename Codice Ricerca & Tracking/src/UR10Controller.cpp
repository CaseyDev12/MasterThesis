#include <UR10Controller.h>

UR10Controller::UR10Controller(ros::NodeHandle& n,string topic_pub, string topic_sub,string ft_sensor_topic_sub,const string& log_path, bool log_enabled, bool debug_enabled):RobotController(UR10_DOFS, UR10_SAMPLE_TIME,log_path,UR10_NAME_LOG, log_enabled,debug_enabled)
,max_dx(MAX_DX),max_ddx(MAX_DDX),selection_vec(N_X){
	robot_pub  = n.advertise<ur10_utils::Data>(topic_pub, 1000);
	robot_sub  = n.subscribe<ur10_utils::Reference>(topic_sub,1000,&UR10Controller::robotJointStateCallback,this);

	comau_pub = n.advertise<comau_coop_utils::Reference>("/comau_coop/reference", 1000);
	comau_sub = n.subscribe("/comau_coop/state", 1000, &UR10Controller::comauJointStateCallback, this);
	
		
	//Kinematics init

	//IMPORTANTE!!!!! INSERIRE LE MATRICI PER RIGHE	
		
	// Matrice che esprime la terna della base dell'UR10 nella terna mondo
	double Ab0[4][4]={{1, 0, 0, -0.81}, {0, -1, 0, 2.8428}, {0, 0, -1, 2.2512}, {0, 0, 0, 1}};

	// Matrice che esprime la terna della camera identificata attraverso la calibrazione nella terna n del robot
	double An_cid[4][4]={{-0.9974, -0.0375, 0.0612, -0.0069}, {0.0341, -0.9979, -0.0551, 0.056}, {0.0632, -0.0528, 0.9966, 0.0932}, {0, 0, 0, 1}};


	// Matrice che esprime la terna con cui la camera legge le coordinate dello skeleton nella terna della camera identificata attraverso la calibrazione
	Acid_c[0][0] = 0;
	Acid_c[0][1] = -1;
	Acid_c[0][2] = 0;
	Acid_c[0][3] = 0;
	Acid_c[1][0] = 0;
	Acid_c[1][1] = 0;
	Acid_c[1][2] = -1;
	Acid_c[1][3] = 0;
	Acid_c[2][0] = 1;
	Acid_c[2][1] = 0;
	Acid_c[2][2] = 0;
	Acid_c[2][3] = 0;
	Acid_c[3][0] = 0;
	Acid_c[3][1] = 0;
	Acid_c[3][2] = 0;
	Acid_c[3][3] = 1;

	// Giunti desiderati per la posizione iniziale
	joints_des_init[0] = 1.3607;
	joints_des_init[1] = 5.7064;
	joints_des_init[2] = 1.5844;
	joints_des_init[3] = 5.7699;
	joints_des_init[4] = 5.8973;
	joints_des_init[5] = 5.8441;


	// Punti intermedi traiettoria di ricerca dello skeleton
	// Primo punto
	points_traj_pre_skeleton[0][0] = -0.7651;
	points_traj_pre_skeleton[0][1] = 3.6174;
	points_traj_pre_skeleton[0][2] = 2.3110;
	points_traj_pre_skeleton[0][3] = 0.2551;   
	points_traj_pre_skeleton[0][4] = 1.9079;  
	points_traj_pre_skeleton[0][5] = -1.5465; 
	
	// Secondo punto
	points_traj_pre_skeleton[1][0] = -0.6629;
	points_traj_pre_skeleton[1][1] = 3.5844;
	points_traj_pre_skeleton[1][2] = 2.3967;
	points_traj_pre_skeleton[1][3] = -0.0746;  
	points_traj_pre_skeleton[1][4] = 1.8532;   
	points_traj_pre_skeleton[1][5] = -1.5708; 

	// Terzo punto	
	points_traj_pre_skeleton[2][0] = -0.7061;
	points_traj_pre_skeleton[2][1] = 3.5579;
	points_traj_pre_skeleton[2][2] = 2.3100;
	points_traj_pre_skeleton[2][3] = -0.3686;  
	points_traj_pre_skeleton[2][4] = 1.9273;   
	points_traj_pre_skeleton[2][5] = -1.6180;

	// Quarto punto
	points_traj_pre_skeleton[3][0] = -0.6629;
	points_traj_pre_skeleton[3][1] = 3.5844;
	points_traj_pre_skeleton[3][2] = 2.3967;
	points_traj_pre_skeleton[3][3] = -0.0746;  
	points_traj_pre_skeleton[3][4] = 1.8532;   
	points_traj_pre_skeleton[3][5] = -1.5708;
	
	// Guadagno clik primo ordine
	double kp_clik=80;

	// Inizializzazione oggetto della classe UR10k per l' inversione cinematica
	kin=new UR10k(kp_clik,Ab0,An_cid);
	
 
	//Planner init
	planner = new UR10Planner(dofs, step_time, debug_enabled);	
	std::fill(selection_vec.begin(), selection_vec.end(), true); 
	planner->SetMaxVelocityVector(max_dx);
	planner->SetMaxAccelerationVector(max_ddx);
	planner->SetSelectionVector(selection_vec);

	robot_ready = false;

	// Prendo il tempo attuale
	struct tm *aTime = localtime(&theTime);
	day = aTime->tm_mday;
	month = aTime->tm_mon + 1; // Month is 0 – 11, add 1 to get a jan-dec 1-12 concept
	year = aTime->tm_year + 1900; // Year is # years since 1900
	hour=aTime->tm_hour;
	min=aTime->tm_min;

	// Tempo di campionamento ur10
	double ur10_sample_time = UR10_SAMPLE_TIME;
	// Angolo massimo di variazione tra due posizioni successive dello human
	double max_delta_phi = 0.02;
	// Posizione base dell'ur10 in terna mondo
	double b_mondo[3] = {Ab0[0][3], Ab0[1][3], Ab0[2][3]};
	// Inizializzo oggetto per l'interazione uomo ur10 
	humanRobot = new HumanRobotController(Acid_c, ur10_sample_time, max_delta_phi, b_mondo);

	// Inizializzo oggetto per l'interazione con comau
	comau_inter = new ComauInteraction();
	
	ROS_INFO("Created controller UR10, dofs %d, step %f", this->dofs, step_time);


}

UR10Controller::~UR10Controller(){
	
}


double UR10Controller::norm(double a[6], double b[6]) {
	double sum;
	double norm;
	for(int ii=0; ii<6; ii++) {
		sum = sum + pow((a[ii] - b[ii]), 2);
	}
	norm = sqrt(sum);
	return norm;
}

// Calcola la distanza in valore assoluto tra le posizioni di ciascun giunto e restituisce quella massima 
double UR10Controller::computeJointsDistances(double qr[6], double q[6]) {
	double max = 0, dist;
	for(int i=0; i<6; i++)	{
		dist = abs(qr[i] - q[i]);
		if(dist > max)
			max = dist;
	}
	return max;
}


void UR10Controller::scriviFile(string file, double var[], int n) {
		std::ofstream outfile;
		string path = "/home/ros-account/Scrivania/ROS Dir/src/Tesi/Sorrentino/log/" + file + std::to_string(day) + 						std::to_string(month) + std::to_string(year) + std::to_string(hour) + std::to_string(min) + ".txt";
		outfile.open(path, std::ios_base::app);
		string log = "";
		for(int i=0; i<n; i++)
			log += std::to_string(var[i]) + " ";
		log += "\n";
		outfile << log;
		outfile.close();
}


// Nel caso di traiettoria spazio giunti calcola le prossime posizioni ai giunti desiderate tramite pianificazione
// Nel caso di traiettoria spazio operativo calcola la prossima posizione e il prossimo orientamento desiderati e poi
// li inverte per calcolare le posizioni ai giunti relative desiderate
void UR10Controller::updateControlInput(){
	
	if(traj_joints_space) {
		if(first_msg){ // solo se viene chiamata per la prima volta inizializza il percorso
			const int n_path_points = 2;
			double    q_path_matrix[n_path_points][dofs];
			double    time_path_vector[n_path_points];

			//define waypoints through which the robot must pass
			for(int i=0;i<dofs;i++){
				q_path_matrix[0][i]=qr[i];
			}
	
			for(int i=0; i<dofs; i++) {
				if(abs(joints_des_init[i]-qr[i])>M_PI) {
					if(joints_des_init[i] > qr[i])
						q_path_matrix[1][i] = joints_des_init[i] - 2*M_PI;
					else
						q_path_matrix[1][i] = joints_des_init[i] + 2*M_PI;
				} else {
					q_path_matrix[1][i] = joints_des_init[i];
				}
			}
	
			time_path_vector[0] = 0;
			time_path_vector[1] = 10;
		  	planner->init_path(&q_path_matrix[0][0], time_path_vector, n_path_points);
		}
		//compute next positions, velocities and accelerations	
	  	int return_val = -1;
		planner->GetNextPlannerPoint(qd, dqd, ddqd, &return_val);
		if(return_val < 0){	      
			ROS_ERROR("It is impossible to retrieve the next trajectory value. Exit");
			ros::shutdown();
		}
		saveVector(qr,dofs);
	}

	else {
		if(init_new_traj) { // solo se viene chiamata per la prima volta per un dato percorso lo inizializza ed inizializza il clik
							// con la posizione ai giunti attuale
			const int n_path_points = 2;
			double    x_path_matrix[n_path_points][dofs];
			double    time_path_vector[n_path_points];

			//compute position and orientation of the end-effector
    			kin->direct(qd, xd);

			// q_old contains joints positions of the previous sample (it is equal to q0 only for the first sample)
			kin->SetQPrec(qd);

			// Initial position
			for(int ii=0; ii<6; ii++)
				x_path_matrix[0][ii] = xd[ii];

			// Final position
			for(int ii=0; ii<6; ii++)
				x_path_matrix[1][ii] = points_traj_pre_skeleton[index_traj_pre_skeleton][ii];
								

			// Time vector 
			time_path_vector[0] = 0;
    		time_path_vector[1] = TIME_FINAL_TRAJ_OPER_SPACE;
			

			if(planner->init_path(&x_path_matrix[0][0], time_path_vector, n_path_points)){
			
			} else {
				ROS_ERROR("Cannot initialize the planner. Check via point definitions. Exit");
     			ros::shutdown();
			}   
		}

		//compute next positions, velocities and accelerations
		int return_val = -1;
		planner->GetNextPlannerPoint(xd, dxd, ddxd, &return_val);

		ROS_INFO("%f %f %f %f %f %f", xd[0], xd[1], xd[2], xd[3], xd[4], xd[5]);		

		if(return_val < 0){	      
			ROS_ERROR("It is impossible to retrieve the next trajectory value. Exit");
			ros::shutdown();
		}
	

		//compute inverse kinematic
    		kin->inverse_cin(dxd, xd, kin->getGain(), UR10_SAMPLE_TIME, dqd, qd);

		
		double x_inv[6];
		kin->getx(x_inv);	
		//scriviFile("x_inversione_pianificata", x_inv, 6);
	
		saveVector(qr,dofs);    
	}
}


// Nel caso in cui una persona viene persa e non viene trovato nessuno per un determinato lasso di tempo
// allora vengono resettate tutte le variabili di controllo del programma e si riparte dalla traiettoria di ricerca
void UR10Controller::reset_program() {
	timeout_research = 0;
	traj_joints_space = true;
	follow_human = false;
	ik = true;
	end_traj = true;
	init_new_traj = false;
	traj_time = 0;
	count = 0;
	index_traj_pre_skeleton = 0;
	wait_time = 0;
	first_msg = true;
	humanRobot->ik = true;
	humanRobot->lost_human = true;
	humanRobot->clearFilter();
}


// Callback relativa alla lettura da topic delle posizioni dell'"oggetto" trasportato dai comau
void UR10Controller::comauJointStateCallback(const comau_coop_utils::Data& msg) {
	
	// Leggo la posizione dell'oggetto manipolato dai robot comau 
	for (int i = 0; i < 3; i++){ 
		pos_obj_comau[i]   = msg.sigma[i];
	}
}



// Callback relativa alla lettura da topic delle posizioni ai giunti dell'ur10
// Quando questa viene richiamata il programma procede nel suo funzionamento. Viene richiamata ogni 0.008 s
void UR10Controller::robotJointStateCallback(const ur10_utils::Reference::ConstPtr& msg){

	ROS_DEBUG("CALLBACK");

	//ROS_INFO("Callback");
	//Read the current state of the robot
	for (int i = 0; i <dofs; i++){ 
		qr[i]   = msg->js.position[i];
		dqr[i] = msg->js.velocity[i];
	}


	if(robot_ready) {
		//scriviFile("qr", qr, 6);
		//scriviFile("dqr", dqr, 6);	
	}

	if(msg->command==(int) Commands::drive_on){//if the robot is in drive_on
		robot_ready = true;
	}

	//if first_msg fill the vector q0
	if(robot_ready && first_msg){
		for (int i = 0; i < dofs; i++){
			q0[i] = qr[i];
		}
	} 


	//Fill the data to publish
	ur10_utils::Data smsg;
	smsg.command = (int) Commands::drive_on;
	trajectory_msgs::JointTrajectoryPoint p;

	// Se i giunti del robot si trovano già nella configurazione desiderata non viene eseguita la traiettoria spazio giunti
	if(first_msg && robot_ready && computeJointsDistances(qr, this->joints_des_init) < 0.005) {
		traj_joints_space = false;
		for(int ii=0; ii<6; ii++)
			qd[ii] = qr[ii];
	}

	// Se la configurazione reale ai giunti è diversa da quella desiderata viene eseguita una triettoria spazio giunti
	if(robot_ready && traj_joints_space) {
		//if the robot is in drive_on, the trajectory can start (qr is a consistent vector)
		updateControlInput();
		
		// Controllo che le posizioni ai giunti lette e desiderate non differiscano di 2*PI
		for(int i=0; i<6; i++) {
			if(abs(qd[i] - qr[i]) > M_PI)
				if(qd[i] > qr[i])
					qd[i] = qd[i] - 2*M_PI;
				else
					qd[i] = qd[i] + 2*M_PI;
		}

		for (int i = 0; i <dofs; i++) {	
			p.positions.push_back(qd[i]);
			p.velocities.push_back(dqd[i]);	 
		}

		//scriviFile("q_scritte", qd, 6);
		//scriviFile("dq_scritte", dqd, 6);


		first_msg=false;
		
		// Controllo se il robot è arrivato nella configurazione desiderata per poter procedere con la logica del programma
		// Controllo dunque se le velocità ai giunti sono nulle
		if(norm(dqd, dq0) < 1e-7) {
			traj_joints_space = false;
		}
	} else if(traj_joints_space) {  // se ancora non è arrivato il robot_ready invia le posizoni che leggi
		for (int i = 0; i <dofs; i++) {	
			p.positions.push_back(qr[i]);
			p.velocities.push_back(0);	 
		}
	}

	// Calcolo la cinematica diretta a partire dalle posizioni ai giunti lette da topic
	if(robot_ready && CHECK_SKEL) {
		// Direct kinematics
		kin->direct(qr,x);
		//scriviFile("x", x, 6);
	}


	// Check skeleton
	if(robot_ready && CHECK_SKEL && !traj_joints_space) { 
		
		// Se non ho ancora trovato una persona e la sto cercando inizializzo le variabile in modo da poterle utilizzare
		// nel modo giusto non appena viene trovato qualcuno
		if(humanRobot->lost_human && wait_time <= WAIT && wait_time >= 0.008) {
			kin->SetQPrec(qr);
			for(int ii=0; ii<3; ii++) {
				eul_fin[ii] = x[ii+3];
				pos_des[ii] = x[ii];
			}
			humanRobot->clearFilter();
		}

		// Look for the skeleton and compute eulero angles and positions desired of the ee
		humanRobot->skeletonPose(x, eul_fin, pos_des, pos_hand);

		// Metto in un unico vettore posizione e orientamento
		for(int i=0; i<3; i++) {		
			x_fin[i] = pos_des[i];
			x_fin[i+3] = eul_fin[i];
		}

		// Se ho trovato una persona calcolo il prossimo punto spazio operativo desiderato per l'ee
		if(!(humanRobot->lost_human)) {
			humanRobot->computeNextDesiredPoint(x, x_fin, xd, dxd);
			follow_human = true;
			ROS_INFO("Follow human = %d",follow_human);
		}


	}

	// Calcolo il delta desiderato per il task eseguito dai comau sulla base della distanza tra lo human e l'oggetto trasportato	
	// Nel caso in cui lo human non è stato ancora trovato il delta è nullo
	// Pubblico tale delta su topic
	if(robot_ready) {
		
		//pos_obj_comau[0] = 0;
		//pos_obj_comau[1] = 2.2; 
		//pos_obj_comau[2] = 1.5;
			
		comau_inter->computeDisplacementComau(pos_obj_comau, pos_hand, deltaPos, deltaVel, deltaAcc, humanRobot->lost_human, f);

		//scriviFile("forze_generate_oggetto", f, 3);

		//scriviFile("deltaPos", deltaPos, 3);
		//scriviFile("deltaVel", deltaVel, 3);
		//scriviFile("deltaAcc", deltaAcc, 3);

		double p0[3] = {0,0,0};
		if(humanRobot->lost_human) {
			//scriviFile("posizioni_persona_completo", p0, 3);
		} else {
			//scriviFile("posizioni_persona_completo", pos_hand, 3);
			//scriviFile("posizioni_persona", pos_hand, 3);
			//scriviFile("posizione_oggetto", pos_obj_comau, 3);
		}
		//scriviFile("posizione_oggetto_completo", pos_obj_comau, 3);

		double dist_obj_hum[1];
		if(humanRobot->lost_human)
			dist_obj_hum[0] = sqrt(pow((pos_obj_comau[0]-p0[0]),2) + pow((pos_obj_comau[1]-p0[1]),2) + pow((pos_obj_comau[2]-p0[2]),2));
		else {
			dist_obj_hum[0] = sqrt(pow((pos_obj_comau[0]-pos_hand[0]),2) + pow((pos_obj_comau[1]-pos_hand[1]),2) + pow((pos_obj_comau[2]-pos_hand[2]),2));
			//scriviFile("dist_obj_human", dist_obj_hum, 1);
		}

		ROS_INFO("DeltaPos = %f, %f, %f", deltaPos[0], deltaPos[1], deltaPos[2]);
		

		//Fill the data to publish for comau
		comau_coop_utils::Reference reference_comau;
		for(int i=0; i<3; i++) {
			reference_comau.deltasigma[i] = deltaPos[i];
			reference_comau.deltadsigma[i] = deltaVel[i];
			reference_comau.deltaddsigma[i] = deltaAcc[i];
		}
		for(int i=3; i<6; i++) {
			reference_comau.deltasigma[i] = 0;
			reference_comau.deltadsigma[i] = 0;
			reference_comau.deltaddsigma[i] = 0;
		}
		comau_pub.publish(reference_comau);

	}


	// Logica di movimentazione dell'ur10 dopo la triettoria ai giunti iniziale
	if(CHECK_SKEL && !traj_joints_space) {	
		if(robot_ready) { 
			
			// Se è stata trovata una persona bisogna invertire le posizioni desiderate spazio operativo
			// calcolate in precedenza
			if(follow_human) {
			
				// Aggiorno le xd con le x effettive
				if(humanRobot->lost_human) {
					for(int ii=0; ii<6; ii++) {
						xd[ii] = x[ii];
						dxd[ii] = 0;
					}
				}

				saveVector(qr,dofs); 


				// Se viene persa una persona devo portare le velocità a zero in modo non istantaneo
				// per fermare il robot in modo dolce
				if(humanRobot->lost_human) {          
					if(!stop_robot && norm(dqd, dq0) > 1e-3) {
						stop_robot = true;
						filter_stop_traj = new Filter(dqd, 6, 1, 1, 0.008);
						for(int i=0; i<6; i++) {
							qd_prec[i] = qr[i];
						}
					}
					if(stop_robot && norm(dqd, dq0) > 1e-3) {
						filter_stop_traj->computeOutput(dq0, dqd);
						for(int i=0; i<6; i++) {
							qd[i] = qd_prec[i] + 0.008 * dqd[i]; 
							qd_prec[i] = qd[i];
						}
						humanRobot->lost_human = true;
						for (int i = 0; i <dofs; i++) {	
							p.positions.push_back(qd[i]);
							p.velocities.push_back(dqd[i]);
						}
					} else {
						//error_joint = false;
						stop_robot = false;
						for (int i = 0; i <dofs; i++) {	
							p.positions.push_back(qr[i]);
							p.velocities.push_back(0);	 
						}
						timeout_research++;
					}
				} else {
					// Cinematica inversa
					kin->inverse_cin(dxd, xd, kin->getGain(), UR10_SAMPLE_TIME, dqd, qd);
					for (int i = 0; i <dofs; i++) {	
						p.positions.push_back(qd[i]);
						p.velocities.push_back(dqd[i]);
					}
					//scriviFile("q_insegue", qd, 6);
					//scriviFile("qr_insegue", qr, 6);
				}

				//scriviFile("q_scritte", qd, 6);
				//scriviFile("dq_scritte", dqd, 6);
		
				robot_time=robot_time+step_time;

				first_msg=false;


			} else{ // Se non è stato trovato nessuno l'ur10 alterna una fase in cui sta fermo e aspetta di calibrare una persona
					// e una fase di inversione che serve a portarsi in un altro punto per inquadrare un'altra zona della scena
					// A quel punto si ferma nuovamente e aspetta di effettuare una calibrazione. Fa questo ciclicamente.
				if(TRAJ_PRE_SKELETON) { // Fase in cui sta fermo e aspetta di calibrare una persona
					if(end_traj && wait_time < WAIT) {
						humanRobot->ik = false;
						humanRobot->lost_human = true;
						//humanRobot->clearFilter();
						follow_human = false;

						for (int i = 0; i <dofs; i++) {	
							p.positions.push_back(qr[i]);
							p.velocities.push_back(0);	 
						}


						//scriviFile("q_fase_inv", qr, 6);
						//scriviFile("qr_fase_inv", qr, 6);

						//scriviFile("q_scritte", qr, 6);
						//scriviFile("dq_scritte", dq0, 6);					

						wait_time = wait_time + UR10_SAMPLE_TIME;
						ROS_INFO("%f", wait_time);
						if(wait_time >= WAIT) {
							end_traj = false;
							init_new_traj = true;	
							humanRobot->ik = true;
						}	
					} else { // Fase di inversione per portarsi in un altro punto desiderato
						
						//humanRobot->ik = true;
						//humanRobot->lost_human = true;
						//humanRobot->clearFilter();
						//follow_human = false;
						
						updateControlInput();
						traj_time = traj_time + UR10_SAMPLE_TIME;

						for(int i=0; i<6; i++) {
							if(abs(qd[i] - qr[i]) > M_PI)
								if(qd[i] > qr[i])
									qd[i] = qd[i] - 2*M_PI;
								else
									qd[i] = qd[i] + 2*M_PI;
						}

						for (int i = 0; i <dofs; i++) {	
							p.positions.push_back(qd[i]);
							p.velocities.push_back(dqd[i]);	 
						}

						//scriviFile("q_scritte", qd, 6);
						//scriviFile("dq_scritte", dqd, 6);

				
						//scriviFile("q_fase_inv", qd, 6);
						//scriviFile("qr_fase_inv", qr, 6);

						// Viene eseguito se la traiettoria è al primo campione
						if(init_new_traj) {
							init_new_traj = false;
							first_msg=false;						
						}

					
						robot_time=robot_time+step_time;
						
						// I due if vengono eseguiti solo se la traiettoria è finita
						// La traiettoria spazio operativo è finita e aggiorno le variabili di controllo per attendere un certo tempo fermi
						if(traj_time > (TIME_FINAL_TRAJ_OPER_SPACE + 1)) {
							end_traj = true;
							ik = false;	
							humanRobot->ik = false;					
						}
						if(end_traj && wait_time >= WAIT) {
							index_traj_pre_skeleton++;
							if(index_traj_pre_skeleton == (sizeof points_traj_pre_skeleton/ sizeof points_traj_pre_skeleton[0]))
								index_traj_pre_skeleton = 0;
							wait_time = 0;
							traj_time = 0;
							ik = true;
						}
					}	
				} else {  // Se non c'è alcuno human e non voglio eseguire la triettoria di ricerca allora invio le posizioni lette da topic e velocità nulle
					for (int i = 0; i <dofs; i++) {	
						p.positions.push_back(qr[i]);
						p.velocities.push_back(0);	 
					}

					//scriviFile("q_scritte", qr, 6);
					//scriviFile("dq_scritte", dq0, 6);

				}			
			}
		} else { // Se non è arrivato il ready invio le posizioni lette da topic e velocità nulle
			for (int i = 0; i <dofs; i++) {	
				p.positions.push_back(qr[i]);
				p.velocities.push_back(0);	 
			}

			//scriviFile("q_scritte", qr, 6);
			//scriviFile("dq_scritte", dq0, 6);		

		}
	}	



	// Se non sono attivi né la traiettoria spazio giunti né l'interazione uomo robot allora l'ur10 
	// viene mantenuto nella configurazione corrente
	if(!CHECK_SKEL && !traj_joints_space) {
		for (int i = 0; i <dofs; i++) {	
			p.positions.push_back(qr[i]);
			p.velocities.push_back(0);	 
		}
	}

	
	// Calcolo l'errore ai giunti e lo salvo su file
	if(robot_ready) {
		double q_err[6];
		for(int i=0; i<6; i++)
			q_err[i] = p.positions[i] - qr[i];
		//scriviFile("q_err", q_err, 6);
	}


	// Pubblico su topic le posizioni e le velocità ai giunti desiderate
	smsg.j.points.push_back(p);

	robot_pub.publish(smsg);

	// Se l'ur10 non trova una persona entro TIMEOUT_DETECTION secondi da quando ha perso la precedente allora ricomincia la ricerca
	if((timeout_research*0.008) > TIMEOUT_DETECTION) {
		reset_program();
	}


}





