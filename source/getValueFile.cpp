#include "../include/masterStructure.h"
#include "../include/functions.h"
std::ifstream readfile;
void gate :: getValueFile(){

	message(2);
	readfile.open("./input/primaryValues", std::ios::in);
	if (readfile.is_open()){
		std::cout << std::string((100),'-') << std::endl;
		printf(" *** File exists ... ***\n\n");
		float *var = new float[14];

		for(int i=0;i<14;i++)
			readfile >> var[i];

		number = int(var[0]);
		length = int(var[1]);
		width  = int(var[2]);
		timeSeries = int(var[3]);
		noise  = var[4];
		coupling = var[5];
		dtime = var[6];
		mean  = var[7];
		variance = var[8];
		orienR = var[9];
		phaseR = var[10];
		viewField = var[11];
		epsilon = var[12];
		speed  = var[13]; 

		tSteps = int( timeSeries / dtime );
	
	}else{
		printf(" *** Error !!! It seems there is no file ...\n Try again ...\n");
		exit(EXIT_FAILURE);
	}
}
