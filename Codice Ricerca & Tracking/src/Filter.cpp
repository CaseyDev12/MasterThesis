#include "Filter.h"

//Filter::Filter(double x0[], char mode[], int dim) {

Filter::Filter(double x0[], int dimension, double wn, double zita, double Tcamp) {

	// Lunghezza vettore da filtrare
	this->dim = dimension;

	// coeff_num[2]*z^2 + coeff_num[1]*z + coeff_num[0]
	coeff_num[0] = (pow(Tcamp,2)*pow(wn,2)) / (pow(Tcamp,2)*pow(wn,2) + 4*zita*Tcamp*wn + 4);
	coeff_num[1] = (2*pow(Tcamp,2)*pow(wn,2)) / (pow(Tcamp,2)*pow(wn,2) + 4*zita*Tcamp*wn + 4);
	coeff_num[2] = coeff_num[0];

	// coeff_den[2]*z^2 + coeff_den[1]*z + coeff_den[0]
	coeff_den[0] = (pow(Tcamp,2)*pow(wn,2) - 4*zita*Tcamp*wn +4) / (pow(Tcamp,2)*pow(wn,2) + 4*zita*Tcamp*wn + 4);
	coeff_den[1] = (2*pow(Tcamp,2)*pow(wn,2) - 8) / (pow(Tcamp,2)*pow(wn,2) + 4*zita*Tcamp*wn + 4);
	coeff_den[2] = 1;
	
	// Inizializzo le uscite e gli ingressi del filtro
	this->x0 = new double[dim];
	this->y_kmeno2 = new double[dim];
	this->y_kmeno1 = new double[dim];
	this->u_kmeno2 = new double[dim];
	this->u_kmeno1 = new double[dim];
	this->u_k = new double[dim];
	this->y_k = new double[dim];

	for(int ii=0; ii<dim; ii++)
		this->x0[ii] = x0[ii];

	for(int ii=0; ii<dim; ii++) {	
		y_kmeno2[ii] = 0;
		y_kmeno1[ii] = 0;
		u_kmeno2[ii] = 0;
		u_kmeno1[ii] = 0;
	}
	
}


Filter::~Filter(){
	
}


void Filter::computeOutput(double x[], double xk[]) {

	ROS_INFO("Num filter: %f, %f, %f", coeff_num[2], coeff_num[1], coeff_num[0]);
	ROS_INFO("Den filter: %f, %f, %f", coeff_den[2], coeff_den[1], coeff_den[0]);

	for(int ii=0; ii<dim; ii++)	
		u_k[ii] = x[ii] - x0[ii];
	
	for(int ii=0; ii<dim; ii++) {

		y_k[ii] = -(coeff_den[1]/coeff_den[2])*y_kmeno1[ii] - (coeff_den[0]/coeff_den[2])*y_kmeno2[ii] + (coeff_num[2]/coeff_den[2])*u_k[ii] + (coeff_num[1]/coeff_den[2])*u_kmeno1[ii] + (coeff_num[0]/coeff_den[2])*u_kmeno2[ii];
		
		xk[ii] = y_k[ii] + x0[ii];

		y_kmeno2[ii] = y_kmeno1[ii];
		y_kmeno1[ii] = y_k[ii];
		u_kmeno2[ii] = u_kmeno1[ii];
		u_kmeno1[ii] = u_k[ii];

	}

}







