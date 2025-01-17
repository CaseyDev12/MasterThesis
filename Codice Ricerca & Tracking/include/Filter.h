#ifndef FILTER_HPP_
#define FILTER_HPP_

#include <ros/ros.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

/*
* La classe implementa un filtro del secondo ordine
*/

class Filter {

	private:
		double coeff_num[3];
		double coeff_den[3];				
		double * x0;
		double * u_kmeno2;
		double * y_kmeno2;
		double * u_kmeno1;
		double * y_kmeno1;
		double * u_k;
		double * y_k;
		int dim;

	public:
		//Filter(double x0[], char mode[], int dim);
		Filter(double x0[], int dimension, double wn, double zita, double Tcamp);
		~Filter();
		void computeOutput(double x[], double xk[]);	


};


#endif
