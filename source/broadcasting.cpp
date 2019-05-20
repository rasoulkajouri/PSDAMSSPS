#include "../include/masterHeader.h"
#include <mpi.h>

void swimmer :: broadcasting(){

	MPI_Bcast(&orientation,1,MPI_FLOAT,0,MPI_COMM_WORLD);
	MPI_Bcast(&phase,1,MPI_FLOAT,0,MPI_COMM_WORLD);	
	MPI_Bcast(&xPosition,1,MPI_FLOAT,0,MPI_COMM_WORLD);
	MPI_Bcast(&yPosition,1,MPI_FLOAT,0,MPI_COMM_WORLD);

}
