#include "../include/storeStructure.h"
std::ofstream outing;
void store :: printPosition(){

	outing.open("./output/position.xyz", std::ios::trunc | std::ios::out);
	
	for (int X=0;X<numArray;X++){
		outing << number <<'\n'<< "Atoms PCSXY  " << X <<'\n';
		for(int Y=0;Y<number;Y++){
			outing << phaseArray[X][Y] <<'\t'<< cos(orienArray[X][Y]) <<'\t'<< sin(orienArray[X][Y])
			<<'\t'<< xPosArray[X][Y] <<'\t'<< yPosArray[X][Y]<<'\n';
		}
	}

	outing.close();
}
