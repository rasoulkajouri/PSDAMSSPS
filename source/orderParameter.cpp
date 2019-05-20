#include "../include/masterHeader.h"
#include "../include/measurmentStructure.h"

void swimmer :: orderParameter(struct measurment* order){

	const std::complex <float> J(0,1);

	(*order).orientationOrder += std :: exp(J * orientation);
	(*order).phaseOrder += std :: exp(J * phase);

//	std::cout << "orienorder: " << orientation <<" J: "<< J << " Times: "<< std::exp(J*orientation) << " value: " <<(*order).orientationOrder << '\n';
}
