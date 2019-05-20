#include "../include/measurmentStructure.h"

std::ofstream output;
void measurment :: printOrderParameter(const float dtime){

	output.open("./output/orderparameter", std::ios::trunc | std::ios::out);

	for(int x=0;x<numArray;x++)
		output << x*dtime <<'\t'<< orientationOrderArray[x] <<'\t'<< phaseOrderArray[x] <<'\n';

	output.close();
}
