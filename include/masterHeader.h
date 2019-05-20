#ifndef MASTERHEADER_H
#define MASTERHEADER_H

#include "functions.h"
#include "masterStructure.h"
#include "storeStructure.h"

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iterator>
#include <ctime>
#include <mpi.h>
#include <cmath>
#include <complex>

# define Pi 3.14159265359
# define TwoPi 2 * Pi

class swimmer{
private:
	int num, length, width, timeSeries;
	float noiseStrength, couplingStrength, dtime, orienR, phaseR, viewField;
	float orientation, phase, xPosition, yPosition, angularVel, mean, variance, epsilon;
	float speed;

	bool equality, is_neighbour;
public:
	swimmer (int var1, int var2, int var3, int var4, float var5, float var6, float var7,
					 float var8, float var9, float var10,float var11, float var12, float var13, float var14): num(var1),
						length(var2), width(var3), timeSeries(var4), noiseStrength(var5), couplingStrength(var6), dtime(var7), 
						 mean(var8), variance(var9),orienR(var10), phaseR(var11), viewField(var12), epsilon(var13), speed(var14){ 
						  equality = (orienR==phaseR)?false:true; }
	// Methods
	void getBackValueClass();
	void initialization();
	void broadcastingAngularVelocity();
	void timeEvolution(swimmer* agent[], float*, float*, const int, const int);
	void broadcasting();
	void substitute(struct store* doer, int i, int c);
	void display(){}
	void checkPhase(const int C, float *phaseTemp);
	void placement(const int C, float *phaseTemp, float *orientationTemp);
	void orderParameter(struct measurment* order);
	void updatingPosition();
	void allocation(const int, float*, float*);

	bool distanceVicsekZone(swimmer* agent[], const int i, const int j);
	bool distanceKuramotoZone(swimmer* agent[], const int i, const int j);

	double generateGaussianNoise();

	};
#endif
