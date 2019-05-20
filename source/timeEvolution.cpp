#include "../include/masterHeader.h" 
#include "uniformSec.h"
void swimmer :: timeEvolution(swimmer* agent[], float *phaseTemp, float *orientationTemp, const int C, const int i){

//	std::cout <<"P: "<< i <<" orien: "<< orientationTemp[C];
	int count = 0;
	float sum	= 0,
				sumSinPhase = 0,
				sumCosPhase = 0,
				localOrderP = 0,
				sumSinAngle = 0,
				sumCosAngle = 0;

	for(int j=0;j<num;j++){
		is_neighbour = equality;
		if(distanceVicsekZone(agent, i, j)){
			sumSinAngle += sin(agent[j]->orientation);
			sumCosAngle += cos(agent[j]->orientation);
			if(orienR<=phaseR){
				sum += sin(agent[j]->phase - phase); 
				count++;
				sumSinPhase += sin(agent[j]->phase);
				sumCosPhase += cos(agent[j]->phase);
				is_neighbour = false;
			}
		}
		if(is_neighbour && distanceKuramotoZone(agent, i, j)){
			sum += sin(agent[j]->phase - phase);
			count++;

			sumSinPhase += sin(agent[j]->phase);
			sumCosPhase += cos(agent[j]->phase);
		}
	}

	//std::cout <<" P: "<< i <<" C: "<< count << '\n';
	
	sum *= couplingStrength / count;
	phaseTemp[C] += dtime * (angularVel + sum);

	checkPhase(C, phaseTemp);

	localOrderP = atan2(sumSinPhase, sumCosPhase);
	localOrderP += (localOrderP<0)? TwoPi : 0;

	orientationTemp[C] = atan2(sumSinAngle, sumCosAngle);
	orientationTemp[C] += (orientationTemp<0) ? TwoPi : 0;

	orientationTemp[C] += (noiseStrength>0) ? ((2.0 * Pi * uniform_sec() - Pi) * noiseStrength) : 0;
	orientationTemp[C] += epsilon * sin(localOrderP - phase);
}
