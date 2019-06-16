#ifndef COMAUINTERACTION_HPP_
#define COMAUINTERACTION_HPP_

#define _USE_MATH_DEFINES
#include<math.h>


/* 
* La classe ComauInteraction implementa la legge di impedenza con cui viene calcolato il delta sul task da inviare ai 
* robot Comau
*/


class ComauInteraction {

private:
	double fMax;
	double dMax;
	double dMin;
	double deltaPos_prec[3];
	double deltaVel_prec[3];
	double KP; 
	double KD;

public:
	ComauInteraction();
	~ComauInteraction();
	void computeDisplacementComau(double pos_obj[3], double pos_human[3], double deltaPos[3], double deltaVel[3], double deltaAcc[3], bool lost_human, double f[3]);


};


#endif
