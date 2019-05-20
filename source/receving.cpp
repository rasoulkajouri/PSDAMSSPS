#include "../include/functions.h"
#include "../include/masterHeader.h"
#include <mpi.h>
void receving(const int numCores, struct gate value, class swimmer* agent[], float *phaseTemp, float *orientationTemp){
	MPI_Status status;

	int C2=0;		
	for(int C=0; C<value.stock;++C,++C2) agent[C2] -> placement(C, phaseTemp, orientationTemp);

	for(int id=1;id<numCores;++id){
		MPI_Recv(orientationTemp,value.stock,MPI_FLOAT,id,1,MPI_COMM_WORLD,&status);
		MPI_Recv(phaseTemp,value.stock,MPI_FLOAT,id,2,MPI_COMM_WORLD,&status);

	/*std::cout << "form 0: \n";
	for(int i=0;i<value.stock;i++)
		std::cout << "I: " << i << ' ' << orientationTemp[i] << '\n';
*/
		for(int C=0; C<value.stock;++C,++C2) agent[C2] -> placement(C, phaseTemp, orientationTemp);

	}
}
