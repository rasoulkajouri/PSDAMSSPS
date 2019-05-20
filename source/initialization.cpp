#include "../include/masterHeader.h"
#include "uniformSec.h"

void swimmer :: initialization(){

	orientation = uniform_sec() * TwoPi;
	phase = uniform_sec() * TwoPi; 
	xPosition = uniform_sec() * length;
	yPosition = uniform_sec() * width;
	angularVel = generateGaussianNoise();

//	std::cout <<" orien: " << orientation << std::endl;
	}
