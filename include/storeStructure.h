#ifndef STORESTRUCTURE_H
#define STORESTRUCTURE_H

#include <cstdio>
#include <fstream>
#include <cmath>

struct store{
public:
	int numArray, number;
	float **xPosArray, **yPosArray;
	float **orienArray, **phaseArray;

	store (int var1, int var2) : numArray(var1), number(var2){ 

		xPosArray = new float *[numArray];
		yPosArray = new float *[numArray];
		orienArray = new float *[numArray];
		phaseArray = new float *[numArray];

		for (int i=0;i<numArray;i++){

			xPosArray[i] = new float [number];
			yPosArray[i] = new float [number];
			orienArray[i] = new float [number];
			phaseArray[i] = new float [number];

		}

	}
	
	void printPosition();
};
#endif// STORESTRUCTURE_H
