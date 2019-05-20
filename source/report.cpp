#include "../include/masterStructure.h"
std::ofstream repo;
void gate :: report(){

	repo.open("./output/report", std::ios::trunc | std::ios::in);

	repo << std::string((100),'*') << std::endl
			 <<"* Number of swimmers: "<< number << std::endl
			 <<"* Lenght of the box:  "<< length << std::endl
			 <<"* Width  of the box:  "<< width  << std::endl
			 <<"* whole  of the time's simulation: "<< timeSeries <<" sec."<< std::endl
			 <<"* The interval time is: "<< dtime <<" sec."<< std::endl
			 <<"* The noise and colping strength: "<< noise <<'\t'<< coupling << std::endl
			 <<"* The mean and variance of the Gaussian distro. : "<< mean <<'\t'<< variance << std::endl
			 <<"* The interaction radius for the swimmer's orientation and phase: "<< orienR <<'\t'<< phaseR << std::endl
			 <<"* The view field of each swimmer: "<< viewField << std::endl
			 <<"* The stock of each core: "<< stock <<" swimmer"<< std::endl
			 <<"* The velocity of swimmers: "<< speed << std::endl
			 <<"* The coefficient of the phase's effect on swimmer's orientation is: "<< epsilon << std::endl
			 << std::string((100),'*') << std::endl;
}
