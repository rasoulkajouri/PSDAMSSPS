#ifndef HEIRHEADER_H
#define HEIRHEADER_H

#include "functions.h"
#include "masterHeader.h"

#include <cstdlib>
#include <iostream>
#include <fstream>

struct gate{

	int number, length, width, timeSeries, startPoint, endPoint, stock;
	float noise, coupling, dtime, mean, variance, orienR, phaseR, viewField, epsilon, speed;

	int tSteps;

	void getValue();
	void getValueFile();

	void display(){
		printf(" 1. Number of swimmers: %i\n",number);
		printf(" 2. The length and width of the box: %i %i \n",length,width);
		printf(" 3. The time series and time step: %i %f\n",timeSeries,dtime);
		printf(" 4. The noise and coupling strength respectively: %f %f \n",noise,coupling);
		printf(" 5. The orientation and phase iteraction radius: %f %f\n", orienR, phaseR);
		printf(" 6. The mean and variance of the angular Velocity's distro: %f %f \n", mean, variance);
		printf(" 7. The view field of swimmers: %f\n", viewField);
		printf(" 8. The phase's effect on orientation: %f\n", epsilon);
		printf(" 9. The speed of swimmers: %f\n", speed);
		printf(" 10. The total time steps is: %i\n", tSteps);
		std::cout << std::string((100),'-') << std::endl;
	}
	void limitation(int idCore, int numCores){

			startPoint = idCore * number / numCores;
			endPoint = (idCore+1) * number / numCores;
			stock = endPoint - startPoint;
			//std::cout <<"id: "<< idCore <<" sp: "<< startPoint <<" ep: "<<endPoint<<std::endl; 
	}

	void report();
	};
#endif
