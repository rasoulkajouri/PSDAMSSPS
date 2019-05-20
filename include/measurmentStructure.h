#ifndef MEASURMENTSTRUCTURE_H
#define MEASURMENTSTRUCTURE_H

#include <cmath>
#include <complex>
#include <iostream>
#include <fstream>


struct measurment {
public:
	using comp = std :: complex <float>;
	comp phaseOrder, orientationOrder;

	int numArray, number;
	// average Orientation Order Parameter, average Phase Order Parameter
	float averageOOP, averagePOP;
	// susceptibility of the orientation order parameter, susceptibility of the phase order parameter
	float suscepOOP, suscepPOP;
	float *orientationOrderArray, *phaseOrderArray;

	measurment(int var1, int var2) : numArray(var1), number(var2){

		orientationOrderArray = new float [numArray];
		phaseOrderArray = new float [numArray];
	}

	void storing(const int X){
		orientationOrderArray [X] = fabs(orientationOrder) / number;
		phaseOrderArray [X] = fabs(phaseOrder) / number;

		phaseOrder = (0,0);
		orientationOrder = (0,0);
	
//		std::cout <<"orie: "<<orientationOrder<<"orieArray: "<<orientationOrderArray[X]<<'\n';
	}
	void printOrderParameter(const float);
	void susceptibility();
};

#endif// MEASURMENTSTRUCTURE_H 
