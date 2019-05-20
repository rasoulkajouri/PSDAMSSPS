#include "../include/masterStructure.h"

void gate :: getValue(){
	std::cout << std::string((1),'\n');

	printf(" Enter number of swimmer: ");
	scanf("%i", &number);

	printf(" Enter the length and width of the box respectively: ");
	scanf("%i %i",&length,&width);

	printf(" Enter the whole of time series and the step's size of time: [for instance, 5000 seconds 0.1 seconds] ");
	scanf("%i %f", &timeSeries, &dtime);

	printf(" Enter the noise and coupling srength respectively: ");
	scanf("%f %f",&noise,&coupling);  

	printf(" Enter the mean and variance of the gussian distribution: ");
	scanf("%f %f",&mean,&variance);

	printf(" Enter the orientation and phase interaction radius respectively: ");
	scanf("%f %f",&orienR,&phaseR);

	printf(" Enter the value of view field(0 to 360): [for instance, 30] ");
	scanf("%f", &viewField);

	printf(" Enter the value of phase's effect on orientation: ");
	scanf("%f", &epsilon);

	printf(" Enter speed of swimmers: ");
	scanf("%f", &speed);

	tSteps = int( timeSeries / dtime ); 
	std::cout << std::string((100),'-') << '\n';
}
