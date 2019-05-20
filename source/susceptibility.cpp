#include "../include/measurmentStructure.h"
void measurment :: susceptibility() {

	averageOOP = 0; averagePOP = 0;

	for (int X=0;X<numArray;X++){
		averageOOP += orientationOrderArray [X];
		averagePOP += phaseOrderArray [X];
	}

	averageOOP /= numArray;
	averagePOP /= numArray;

	for (int X=0;X<numArray;X++){
		suscepOOP += orientationOrderArray [X] * orientationOrderArray [X];
		suscepPOP += phaseOrderArray [X] * phaseOrderArray [X];
	}

	suscepOOP /= numArray;
	suscepPOP /= numArray;

	suscepOOP -= averageOOP * averageOOP;
	suscepPOP -= averagePOP * averagePOP;
}
