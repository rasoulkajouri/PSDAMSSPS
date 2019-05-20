#ifndef FUNCTIONS_H
#define FUNCTIONS_H

	#include "masterStructure.h"
	#include "masterHeader.h"

	void message(int);
	void broadcastingStructureValue(struct gate* value);
	void sending(struct gate value, float *phaseTemp, float *orientationTemp);
	void receving(const int numCores, struct gate value, class swimmer* agent[], float *phaseTemp, float *orientationTemp);
	void indicator(const int X, const int Y);
#endif
