#include "../include/functions.h"
#include "../include/masterHeader.h"
#include <mpi.h>

void swimmer :: broadcastingAngularVelocity(){

	MPI_Bcast(&angularVel,1,MPI_FLOAT,0,MPI_COMM_WORLD);

}
