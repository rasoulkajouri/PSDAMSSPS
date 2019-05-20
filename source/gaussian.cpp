#include "../include/masterHeader.h"
#include "./uniformSec.h"
double swimmer :: generateGaussianNoise(){

	double u1,u2;
	static bool has_spare = false;
	static double z0,z1;

	if (has_spare) {
		has_spare = false;
		return z1*variance+mean;
	}

	u1 = uniform_sec();
	u2 = uniform_sec();

	z0 = sqrt(-2.0* log(1-u1)) * cos(TwoPi * u2);
	z1 = sqrt(-2.0* log(1-u1)) * sin(TwoPi * u2);

	has_spare = true;

	return z0*variance+mean;
}
