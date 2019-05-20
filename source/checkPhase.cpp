#include "../include/masterHeader.h"
void swimmer :: checkPhase(const int C, float *phaseTemp){

	while(phaseTemp[C] > TwoPi)
		phaseTemp[C] -= TwoPi;
	while(phaseTemp[C] < 0.0 )
		phaseTemp[C] += TwoPi;
}
