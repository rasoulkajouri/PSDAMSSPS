#include "../include/functions.h"
#include <mpi.h>
void sending(struct gate value, float *phaseTemp, float *orientationTemp){
/*	std::cout<<"from 1\n";
	for(int i=0;i<value.stock;i++)
		std::cout <<"I: "<< i <<' '<< orientationTemp[i] <<'\n';
*/
	MPI_Send(orientationTemp,value.stock,MPI_FLOAT,0,1,MPI_COMM_WORLD);
	MPI_Send(phaseTemp,value.stock,MPI_FLOAT,0,2,MPI_COMM_WORLD);
}
