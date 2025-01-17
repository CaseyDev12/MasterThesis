#include "HumanRobotController.h"

HumanRobotController::HumanRobotController(double Acid_c[4][4], double ur10_sample_time, double max_delta_phi, double b_mondo[3]) {
	// Matrice di roto-traslazione tra la terna camera identificata attraverso la calibrazione e la terna camera in
	// cui vengono lette le coordinate
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			this->Acid_c[i][j] = Acid_c[i][j];

	// Posizione terna relativa alla base dell'ur10
	for(int i=0; i<3; i++)
		this->b_mondo[i] = b_mondo[i];

	// Variabile di controllo per sapere se la kinect sta tracciando una persona o meno
	lost_human = true;

	// Tempo di campionamento ur10
	this->ur10_sample_time = ur10_sample_time;

	// Massimo angolo di cui possono differire due posizioni successive della persona, lette da topic
	this->max_delta_phi = max_delta_phi;

	// Prendo il tempo attuale per salvataggio su file
	struct tm *aTime = localtime(&theTime);
	day = aTime->tm_mday;
	month = aTime->tm_mon + 1; // Month is 0 – 11, add 1 to get a jan-dec 1-12 concept
	year = aTime->tm_year + 1900; // Year is # years since 1900
	hour=aTime->tm_hour;
	min=aTime->tm_min;

}


HumanRobotController::~HumanRobotController() {

}


// Fa il prodotto vettoriale
void HumanRobotController::cross_product(double xc[], double zbc[], double nc[]) {
	nc[0] = xc[1]*zbc[2] - xc[2]*zbc[1];
	nc[1] = xc[2]*zbc[0] - xc[0]*zbc[2];
	nc[2] = xc[0]*zbc[1] - xc[1]*zbc[0];
}

// Norma di un vettore
double HumanRobotController::computeNorm(double x[]) {
	double sum = 0;
	for(int i=0; i<3; i++)
		sum += x[i]*x[i];
	double norm = sqrt(sum);
	return norm;
}

// Calcola l'orientamento desiderato per l'ee dell'ur10 sulla base della posizione corrente della persona rispetto alla camera
void HumanRobotController::computeDesiredOrient(const double human_actual[3], const double Rbc[3][3], const double eul_prec[3], double eul_des[3]) {

	
	// Calcolo delle rotazioni desiderate in terna camera
    double x_human = human_actual[0];
    double y_human = human_actual[1];
    double z_human = human_actual[2];

	double ipotenusaYX = sqrt(pow(x_human,2) + pow(y_human,2));
    double rotZ_camera = asin(y_human / ipotenusaYX);
     
    double ipotenusaZX = sqrt(pow(x_human,2) + pow(z_human,2));
    double rotY_camera = asin(z_human / ipotenusaZX);


	// Rotazioni desiderate in terna camera identificata, ricordando che x = -y, y = -z, z = x
    // Quindi la rotazione intorno a z diventa una rotazione intorno ad y di -rotZ_camera
    // e la rotazione intorno ad y diventa una rotazione intorno ad x di -rotY_camera
    if(y_human>0 && rotZ_camera>0)
        rotZ_camera = -rotZ_camera;
    if(y_human<0 && rotZ_camera<0)
        rotZ_camera = -rotZ_camera;
         
    if(z_human>0 && rotY_camera<0)
            rotY_camera = -rotY_camera;
    if(z_human<0 && rotY_camera>0)
            rotY_camera = -rotY_camera;
     
    double rotY_cameraident = rotZ_camera;
    double rotX_cameraident = rotY_camera;


	// Calcolo la matrice di rotazione desiderata della camera affinché essa inquadri lo human a centro immagine
    double calfa = cos(rotX_cameraident);
    double salfa = sin(rotX_cameraident);
    double cbeta = cos(rotY_cameraident);
    double sbeta = sin(rotY_cameraident);

	double Rx[3][3] = {{1, 0, 0}, {0, calfa, -salfa}, {0, salfa, calfa}};
	double Ry[3][3] = {{cbeta, 0, sbeta}, {0, 1, 0}, {-sbeta, 0, cbeta}};

	double Rcameraid_cameraidDes[3][3];
	double elem;
	for(int ii = 0; ii < 3; ii++) {
		for(int jj = 0; jj < 3; jj++) {
			elem = 0;
			for(int kk = 0; kk < 3; kk++) {
				elem += Ry[jj][kk] * Rx[kk][ii];
			}
			Rcameraid_cameraidDes[jj][ii] = elem;
		}
	}

	double Rbc_des[3][3];
	for(int ii = 0; ii < 3; ii++) {
		for(int jj = 0; jj < 3; jj++) {
			elem = 0;
			for(int kk = 0; kk < 3; kk++) {
				elem += Rbc[jj][kk] * Rcameraid_cameraidDes[kk][ii];
			}
			Rbc_des[jj][ii] = elem;
		}
	}

	// Quanto segue serve ad allineare la camera con il piano x-y della terna mondo, 
	// in modo che essa sia sempre dritta e mai obliqua  

	// Versore x della terna camera
	double xbc[3];
	for(int ii=0; ii<3; ii++)
		xbc[ii] = Rbc_des[ii][0];
	
	// Versore z della camera
	double zbc[3];
	for(int ii=0; ii<3; ii++)
		zbc[ii] = Rbc_des[ii][2];

	// Angolo tra il versore z della camera e l'asse z terna mondo 
	double theta_versore = acos(zbc[2]);
	
	// Angolo tra il versore z della camera e l'asse x terna mondo
	double phi_versore = asin(zbc[1]/sin(theta_versore));

	// Versore xc che insieme a zbc della camera identifica il piano in cui vogliamo portare il versore xbc
	double xc[3];
	xc[0] = cos(-M_PI/2+phi_versore);
	xc[1] = sin(-M_PI/2+phi_versore);
	xc[2] = 0;

	// Versore normale al piano individuato
	double nc[3];
	cross_product(xc, zbc, nc);
	double norm_nc = computeNorm(nc);
	for(int ii=0; ii<3; ii++)
		nc[ii] = nc[ii]/norm_nc;

	// Angolo tra il versore xbc e il piano individuato dalla normale nc
	double prod = 0;
	for(int ii=0; ii<3; ii++)
		prod += nc[ii]*xbc[ii];
	double theta_xbc = asin(prod);
	
	double cz = cos(theta_xbc);
	double sz = sin(theta_xbc);
	double Rz[3][3] = {{cz, -sz, 0}, {sz, cz, 0}, {0, 0, 1}};

	// Moltiplico le precedenti rotazioni per quest'ultima e ottengo la matrice di rotazione
	// finale della camera desiderata
	double Rbc_final[3][3];
	for(int ii = 0; ii < 3; ii++) {
		for(int jj = 0; jj < 3; jj++) {
			elem = 0;
			for(int kk = 0; kk < 3; kk++) {
				elem += Rbc_des[jj][kk] * Rz[kk][ii];
			}
			Rbc_final[jj][ii] = elem;
		}
	}


	// Converto la matrice di rotazione Rbc_des in angoli di Euleroc (ZYZ) desiderati
	double phi = atan2(Rbc_final[1][2], Rbc_final[0][2]);
	double theta = atan2(sqrt(pow(Rbc_final[0][2],2) + pow(Rbc_final[1][2],2)), Rbc_final[2][2]);	
	double psi = atan2(Rbc_final[2][1], -Rbc_final[2][0]);

	// Singolarità di rappresentazione
	if(sin(theta)<1e-6) {
		if(abs(abs(theta)-M_PI)<1e-6) {
			phi = atan2(-Rbc_final[0][1], Rbc_final[1][1]);
			psi = 0;
			theta = M_PI;
		} else {
			phi = atan2(Rbc_final[1][0], Rbc_final[0][0]);
			psi = 0;
		}
	}
	eul_des[0] = phi;
	eul_des[1] = theta;
	eul_des[2] = psi;

	
	for(int ii=0; ii<3; ii++) {
		if(eul_prec[ii]<0 && eul_des[ii]>0 && abs(eul_prec[ii] - eul_des[ii])>M_PI)
			eul_des[ii] = eul_des[ii] - 2*M_PI;
		if(eul_prec[ii]>0 && eul_des[ii]<0 && abs(eul_prec[ii] - eul_des[ii])>M_PI)
			eul_des[ii] = eul_des[ii] + 2*M_PI;
	}


}



// Azzera i filtri utilizzati, nel momento un cui una persona viene persa perché è necessario reinizializzarli
void HumanRobotController::clearFilter() {
	filter_orient = NULL;
	filter_position = NULL;
	filter_head = NULL;
	filter_right_hand = NULL;
}

// A partire dalla posizione e orientamento spazio operativo viene calcolata la matrice di roto-traslazione
// tra la terna base e la terna camera identificata
void HumanRobotController::computeAb_cid(double Ab_cid[4][4], double x[6]) {
	//ZYZ
	double cos_phi=cos(x[3]), sin_phi=sin(x[3]), cos_teta=cos(x[4]), sin_teta=sin(x[4]), cos_psi=cos(x[5]), sin_psi=sin(x[5]);
	Ab_cid[0][0] = cos_phi*cos_teta*cos_psi-sin_phi*sin_psi;
	Ab_cid[0][1] = -cos_phi*cos_teta*sin_psi-sin_phi*cos_psi;
	Ab_cid[0][2] = cos_phi*sin_teta;
	Ab_cid[0][3] = x[0];
	Ab_cid[1][0] = sin_phi*cos_teta*cos_psi+cos_phi*sin_psi;
	Ab_cid[1][1] = -sin_phi*cos_teta*sin_psi+cos_phi*cos_psi;
	Ab_cid[1][2] = sin_phi*sin_teta;
	Ab_cid[1][3] = x[1];
	Ab_cid[2][0] = -sin_teta*cos_psi;
	Ab_cid[2][1] = sin_teta*sin_psi;
	Ab_cid[2][2] = cos_teta;
	Ab_cid[2][3] = x[2];
	Ab_cid[3][0] = 0;
	Ab_cid[3][1] = 0;
	Ab_cid[3][2] = 0;
	Ab_cid[3][3] = 1;
}

// Dalla matrice di roto-traslazione viene estratta la matrice di rotazione
void HumanRobotController::computeRb_cid(double Rb_cid[3][3], double Ab_cid[4][4]) {
	for(int ii=0; ii<3; ii++) {
		for(int jj=0; jj<3; jj++) {
			Rb_cid[ii][jj] = Ab_cid[ii][jj];
		}
	}
}

// Prodotto tra matrici di roto-traslazione
void HumanRobotController::computeAbc(double Abc[4][4], double Ab_cid[4][4]) {
	double elem;
	for(int ii = 0; ii < 4; ii++) {
		for(int jj = 0; jj < 4; jj++) {
			elem = 0;
			for(int kk = 0; kk < 4; kk++) {
				elem += Ab_cid[jj][kk] * this->Acid_c[kk][ii];
			}
			Abc[jj][ii] = elem;
		}
	}
}

// Cambio frame in cui un vettore è espresso
void HumanRobotController::changeFrame(double A[4][4], double x[3], double x_new_frame[3]) {
	double elem;
	for(int jj = 0; jj < 3; jj++) {
		elem = 0;
		for(int kk = 0; kk < 4; kk++) {
			if(kk!=3)
				elem += A[jj][kk] * x[kk];
			if(kk==3)
				elem += A[jj][kk];
		}
		x_new_frame[jj] = elem;
	}
}


void HumanRobotController::writeLog(string file, double var[], int n) {
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

// Calcolo la nuova posizione desiderata per l'ee dell'ur10 sulla base della posizione dello human rispetto alla camera
void HumanRobotController::computeDesiredPosition(double x_torso_mondo[3], double c_mondo[3], double pos_des[3]) {

	double desired_distance = 2.9;
	double nor = sqrt(pow((c_mondo[0]-x_torso_mondo[0]),2) + pow((c_mondo[1]-x_torso_mondo[1]),2) + pow((c_mondo[2]-x_torso_mondo[2]),2));

	double dd[1];
	dd[0] = nor;
	//writeLog("Distance", dd, 1);

	double d_des[3];
	d_des[0] = (c_mondo[0]-x_torso_mondo[0])*desired_distance/nor;
	d_des[1] = (c_mondo[1]-x_torso_mondo[1])*desired_distance/nor;
	d_des[2] = (c_mondo[2]-x_torso_mondo[2])*desired_distance/nor;

	pos_des[0] = x_torso_mondo[0] + d_des[0];
	pos_des[1] = x_torso_mondo[1] + d_des[1];
	pos_des[2] = x_torso_mondo[2] + d_des[2];

	// Voglio che l'ee si mantenga all'interno di un settore di sfera centrata sulla base dell'ur10
	nor = sqrt(pow((pos_des[0]-b_mondo[0]),2) + pow((pos_des[1]-b_mondo[1]),2) + pow((pos_des[2]-b_mondo[2]),2));
	double d_min = 0.5;
	double d_max = 1;
	if(nor > d_max || nor < d_min) {
		if(nor > d_max)
			desired_distance = d_max;
		else
			desired_distance = d_min;
		d_des[0] = (pos_des[0]-b_mondo[0])*desired_distance/nor;
		d_des[1] = (pos_des[1]-b_mondo[1])*desired_distance/nor;
		d_des[2] = (pos_des[2]-b_mondo[2])*desired_distance/nor;
		pos_des[0] = b_mondo[0] + d_des[0];
		pos_des[1] = b_mondo[1] + d_des[1];
		pos_des[2] = b_mondo[2] + d_des[2];
	}
	
	//writeLog("pos_des", pos_des, 3);
	dd[0] = nor;
	//writeLog("Distanza_base_ee", dd, 1);

	// Evito il muro e il comau e che si stenda troppo in altezza
	if(pos_des[0] > -0.3)
		pos_des[0] = -0.3;
	else if(pos_des[0] < -0.9)
		pos_des[0] = -0.9;
	if(pos_des[1] > 3.8)
		pos_des[1] = 3.8;
	else if(pos_des[1] < 3.4)
		pos_des[1] = 3.4;
	if(pos_des[2] > 2.7)
		pos_des[2] = 2.7;
	else if(pos_des[2] < 2.1)
		pos_des[2] = 2.1;


	//writeLog("pos_des_terna_b", pos_des, 3);
}


void HumanRobotController::skeletonPose(double x[6], double eul_final_des[3], double pos_des[3], double pos_hand[3]) {
	
	// Verifico se lo human è stato trovato, leggendo da topic. Se non è presente viene lanciata un'eccezione
	tf::Stamped<tf::Pose> id(tf::Pose(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0, 0, 0)), ros::Time(0), "id");		

	sample_time_camera += ur10_sample_time;


	double Ab_cid[4][4];
	computeAb_cid(Ab_cid, x);
	
	double Rb_cid[3][3];
	computeRb_cid(Rb_cid, Ab_cid);

	double Abc[4][4];
	computeAbc(Abc, Ab_cid);

	try{

		// Cerco una nuova persona leggendo da topic
		if(this->lost_human) {
			tf::Stamped<tf::Pose> transform_id;
			listener.transformPose("openni_depth_frame", id, transform_id);
			int id_temp = (int) transform_id.getOrigin().x();
			double iddd[1];
			iddd[0] = id_temp;

			ROS_INFO("id=%d, ik=%d", id_temp, ik);
			std::vector<int>::iterator it;
			it = find(id_rejected.begin(), id_rejected.end(), id_temp);
			
			// Se la persona viene trovata durante la fase di inversione cinematica viene scartata
			if(ik && it==id_rejected.end()) {
				id_rejected.push_back(id_temp);
			}

			// Se la persona viene trovata durante la fase in cui l'ee è fermo e non era stata scartata 
			// in precedenza allora l'ur10 inizierà a seguirla
			if(!ik && it==id_rejected.end()) {
				if(!id_used) {
					id_user = id_temp;
					id_rejected.clear();
					id_used = true;
				}
				frame_head = "head_" + std::to_string(id_user);

				// Uso il frame left hand, ma essendo l'immagine speculare esso corrisponde alla mano destra
				frame_right_hand = "left_hand_" + std::to_string(id_user);  
			}
		}


		tf::Stamped<tf::Pose> right_hand(tf::Pose(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0, 0, 0)), ros::Time(0), frame_right_hand);	
		tf::Stamped<tf::Pose> head(tf::Pose(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0, 0, 0)), ros::Time(0), frame_head);

		// Leggo da topic i dati relativi alla mano destra
		tf::Stamped<tf::Pose> transform_right_hand;	
		listener.transformPose("openni_depth_frame", right_hand, transform_right_hand);

		// Leggo da topic i dati relativi alla testa
		tf::Stamped<tf::Pose> transform_head;
		listener.transformPose("openni_depth_frame", head, transform_head);

		// Salvo la posizione della testa in terna camera
		double pos_head[3];
		pos_head[0] = transform_head.getOrigin().x(); 
		pos_head[1] = transform_head.getOrigin().y(); 
		pos_head[2] = transform_head.getOrigin().z();

		// Salvo la posizione della mano destra in terna camera
		pos_right_hand[0] = transform_right_hand.getOrigin().x();
		pos_right_hand[1] = transform_right_hand.getOrigin().y();
		pos_right_hand[2] = transform_right_hand.getOrigin().z();

		//writeLog("Testa", pos_head, 3);

		double pos_head_temp[3];
		for(int i=0; i<3; i++) {
			last_pos[i] = pos_head[i];
			pos_head_temp[i] = pos_head[i];
		}


		// Se la persona è stata appena trovata inizializzo i filtri per il filtraggio delle informazioni lette da topic
		if(this->lost_human) {
			this->filter_head = new Filter(pos_head_temp, 3, 4.4, 1, 0.008);
			this->filter_right_hand = new Filter(pos_right_hand, 3, 4.4, 1, 0.008);
		}
		
		// Filtro le posizioni lette da topic
		double pos_head_camera[3];
		filter_head->computeOutput(pos_head_temp, pos_head_camera);
		double pos_right_hand_filtered[3];
		filter_right_hand->computeOutput(pos_right_hand, pos_right_hand_filtered);
	
		// Calcolo la posizione della persona in terna mondo
		double x_head_mondo[3];
		changeFrame(Abc, pos_head_camera, x_head_mondo);
		changeFrame(Abc, pos_right_hand_filtered, pos_hand);

		//writeLog("PosHand", pos_hand, 3);

		//writeLog("TorsoTernaCamFilt", pos_head_camera, 3);
		//writeLog("TorsoTernaMondoFilt", x_head_mondo, 3);


		// Salvo gli angoli di eulero desiderati al passo precedente
		double eul_prec[3];
		if(this->lost_human) {
			for(int ii=3; ii<6; ii++) {
				eul_prec[ii-3] = x[ii];
			}
		} else {	
			for(int ii=3; ii<6; ii++) {	
				eul_prec[ii-3] = eul_fin_pre[ii-3];
			}		
		}

		// Se la persona è stata appena trovata inizializzo i filtri per il filtraggio di posizioni e orientamenti desiderati
		if(this->lost_human) {
			double init_pos[3];
			for(int i=0; i<3; i++)
				init_pos[i] = x[i];
			this->filter_orient = new Filter(eul_prec, 3, 0.5, 1, 0.008);
			this->filter_position = new Filter(init_pos, 3, 0.1, 1, 0.008);
		}
			
		// Calcolo del nuovo orientamento desiderato sulla base della posizione del torso all'interno dell'immagine.
		// Infatti si vuole che il torso sia inquadrato sempre al centro dell'immagine.	
		double eul_fin[3];	
		computeDesiredOrient(pos_head_camera, Rb_cid, eul_prec, eul_fin);


		if(this->lost_human) {
			for(int ii=0; ii<3; ii++)
				eul_fin_pre[ii] = eul_fin[ii];
		} 


		//writeLog("PhiCompleti", eul_fin, 3);		

		// Controllo che l'orientamento desiderato non differisca troppo dall'orientamento desiderato al passo precedente
		// Se ciò accade significa che le posizioni della persona lette da topic non sono attendibili
		// Se le variazioni sono troppo elevate scarto le posizioni e mantengo come orientamento e posizione desiderati quelli precedenti
		if(abs(eul_fin[0]-eul_fin_pre[0]) < max_delta_phi && abs(eul_fin[1]-eul_fin_pre[1]) < max_delta_phi && abs(eul_fin[2]-eul_fin_pre[2]) < max_delta_phi) {
		
			for(int i=0; i<3; i++) {
				eul_final_des[i] = eul_fin[i];
				eul_fin_pre[i] = eul_fin[i];
			}


			// Se non scarta gli angoli non scarterà nemmeno le posizioni
			double c_mondo[3];
			for(int i=0; i<3; i++) {
				c_mondo[i] = x[i];
			}
			computeDesiredPosition(x_head_mondo, c_mondo, pos_des);

			//writeLog("PosizioniDesiderate", pos_des, 3);

			//ROS_INFO("Posizioni desiderate: %f %f %f\n", pos_des[0], pos_des[1], pos_des[2]);

		} 


		sample_time_camera = 0;

		listener.clear();
		
	
		this->human_first = false;	
		this->lost_human = false;

		// Se le posizioni della persona lette da topic vanno oltre quelle possibili nella realtà allora metto lost_human a true 
		// e forzo la condizione in cui una persona viene persa
		if(x_head_mondo[0] > 5 || x_head_mondo[0] < 0.1 || x_head_mondo[1] > 4.1 || x_head_mondo[1] < 1.8 || x_head_mondo[2] > 2.2 || x_head_mondo[2] < 0.5)
			this->lost_human = true;


	} catch(tf::TransformException &ex) {

		// Se per 60 campioni non mi arrivano posizioni della persona allora reinizializzo tutto e considero la persona persa
		if(sample_time_camera>0.008*60) {
			this->lost_human = true;
			count = 0;
			id_user = 0;
			id_used = false;
			frame_head = "";
		}


		// Se non leggo posizioni da topic (dato che la kinect lavora ad un tempo di campionamento non fissato, ma comunque 
		// più lento del tempo di campionamento dell'ur10) allora continuo a considerare le ultime posizioni lette
		// Devo filtrare la posizione letta nell'ultimo try e calcolare gli angoli di eulero associati desiderati
		if(filter_head != NULL && sample_time_camera<=0.008*60) {

			// Filtro le coordinate della testa
			double pos_head_camera[3];
			filter_head->computeOutput(last_pos, pos_head_camera);

			// Filtro le coordinate della mano
			double pos_right_hand_filtered[3];
			filter_right_hand->computeOutput(pos_right_hand, pos_right_hand_filtered);

			double x_head_mondo[3];
			changeFrame(Abc, pos_head_camera, x_head_mondo);

			changeFrame(Abc, pos_right_hand_filtered, pos_hand);
			//writeLog("PosHand", pos_hand, 3);


			double eul_prec[3];
			for(int ii=3; ii<6; ii++) {	
				eul_prec[ii-3] = eul_fin_pre[ii-3];
			}

			double eul_fin[3];	
			computeDesiredOrient(pos_head_camera, Rb_cid, eul_prec, eul_fin);
		

			//writeLog("TorsoTernaCamFilt", pos_head_camera, 3);
			//writeLog("TorsoTernaMondoFilt", x_head_mondo, 3);
			//writeLog("PhiCompleti", eul_fin, 3);
			

			if(abs(eul_fin[0]-eul_fin_pre[0]) < max_delta_phi && abs(eul_fin[1]-eul_fin_pre[1]) < max_delta_phi && abs(eul_fin[2]-eul_fin_pre[2]) < max_delta_phi) {
			
				for(int i=0; i<3; i++) {
					eul_final_des[i] = eul_fin[i];
					eul_fin_pre[i] = eul_fin[i];
				}

				// Se non scarta gli angoli non scarterà nemmeno le posizioni
				double c_mondo[3];
				for(int i=0; i<3; i++) {
					c_mondo[i] = x[i];
				}
				computeDesiredPosition(x_head_mondo, c_mondo, pos_des);

				//writeLog("PosizioniDesiderate", pos_des, 3);

			} 


		}


	}

}


// Filtro posizioni e orientamenti desiderati per far fare movimenti dolci e non troppo veloci al robot
void HumanRobotController::computeNextDesiredPoint(double x[6], double x_fin[6], double xd[6], double dxd[6]) {

	double orient_fin[3];
	double orient_des[3];
	double pos_fin[3];
	double pos_des[3];
	for(int i=0; i<3; i++) {
		orient_fin[i] = x_fin[i+3];
		pos_fin[i] = x_fin[i];
	}

	// I filtri per posizione e orientamento sono separati perché hanno velocità diverse
	filter_orient->computeOutput(orient_fin, orient_des);
	filter_position->computeOutput(pos_fin, pos_des);


	if(count==0)
		for(int i=0; i<6; i++)
			old_sample[i] = x[i];


	for(int ii=0; ii<3; ii++) {
		xd[ii] = pos_des[ii];
		xd[ii+3] = orient_des[ii];
	}

	//writeLog("xd_filtro_inv_online", xd, 6);
	//writeLog("x_filtro_inv_online", x, 6);

	
	for(int ii=0; ii<6; ii++) {
		dxd[ii] = (xd[ii] - old_sample[ii])/ur10_sample_time;
		old_sample[ii] = xd[ii];
	}
	
	count++;

}



