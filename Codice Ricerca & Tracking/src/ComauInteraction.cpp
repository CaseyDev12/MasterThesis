#include "ComauInteraction.h"


ComauInteraction::ComauInteraction() {
	fMax = 1.2; // Forza massima quando la distanza tra l'oggetto e lo human è nulla
	dMax = 2.3; // Distanza massima dalla quale iniziare a calcolare una forza per generare un delta sul task. Se la distanza è maggiore 						la forza sarà nulla
	dMin = 0.6; // Al di sotto di tale distanza la forza applicata sarà data dal valore della funzione f(d) utilizzata, calcolata in 						d=dMin

	for(int i=0; i<3; i++) {
		deltaPos_prec[i] = 0;
		deltaVel_prec[i] = 0;
	}
}

ComauInteraction::~ComauInteraction(){

}


void ComauInteraction::computeDisplacementComau(double pos_obj[3], double pos_human[3], double deltaPos[3], double deltaVel[3], double deltaAcc[3], bool lost_human, double f[3]) {

	// Distanza tra l'oggetto e la mano della persona
	double d = sqrt(pow((pos_obj[0]-pos_human[0]),2) + pow((pos_obj[1]-pos_human[1]),2) + pow((pos_obj[2]-pos_human[2]),2));
	
	double norm_f;

	// Calcolo il modulo della forza limitandolo però se diventa troppo grande o negativo	
	if(d < dMin) {
		norm_f = -fMax * (dMin-dMax) / dMax;
	} else {
		norm_f = -fMax * (d-dMax) / dMax;
	    if(norm_f < 0) {
			norm_f = 0;
		}
	}

	// Se la persona viene persa dalla camera i comau possono seguire il task desiderato,
	// dunque il modulo della forza sarà pari a zero. Ma per evitare di passare in
	// mode molto veloce a zero da un valore magari abbastanza alto, riduciamo la velocità del filtro
	// altrimenti filtriamo comunque la nuova forza desiderata sempre per evitare di avere salti sulla norma
	// della forza troppo elevati
	for(int i=0; i<3; i++) {
		if(lost_human) {
			f[i] = 0;
			// Guadagni filtro --> ddp = f - KD * dp - KP * p   (impedenza)
			KP = 0.05;
			KD = 2*sqrt(KP);
		}
		else {
			f[i] = ((pos_obj[i]-pos_human[i]) / d) * norm_f * KP;
			KP = 1;
			KD = 2*sqrt(KP);	
		}
		deltaAcc[i] = f[i] - KD*deltaVel_prec[i] - KP*deltaPos_prec[i];
		deltaVel[i] = deltaVel_prec[i] + deltaAcc[i]*0.008;
		deltaPos[i] = deltaPos_prec[i] + deltaVel[i]*0.008;
		deltaVel_prec[i] = deltaVel[i];
		deltaPos_prec[i] = deltaPos[i];
	}

}



