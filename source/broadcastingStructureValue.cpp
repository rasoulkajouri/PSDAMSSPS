#include "../include/functions.h"
#include "../include/masterStructure.h"
#include <mpi.h>

void broadcastingStructureValue(struct gate* value){

	MPI_Bcast(&value->number,1,MPI_INT,0,MPI_COMM_WORLD);
	MPI_Bcast(&value->length,1,MPI_INT,0,MPI_COMM_WORLD);
	MPI_Bcast(&value->width,1,MPI_INT,0,MPI_COMM_WORLD);
	MPI_Bcast(&value->timeSeries,1,MPI_INT,0,MPI_COMM_WORLD);
	MPI_Bcast(&value->tSteps,1,MPI_INT,0,MPI_COMM_WORLD);

	MPI_Bcast(&value->noise,1,MPI_FLOAT,0,MPI_COMM_WORLD);
	MPI_Bcast(&value->coupling,1,MPI_FLOAT,0,MPI_COMM_WORLD);
	MPI_Bcast(&value->dtime,1,MPI_FLOAT,0,MPI_COMM_WORLD);
	MPI_Bcast(&value->mean,1,MPI_FLOAT,0,MPI_COMM_WORLD);
	MPI_Bcast(&value->variance,1,MPI_FLOAT,0,MPI_COMM_WORLD);
	MPI_Bcast(&value->orienR,1,MPI_FLOAT,0,MPI_COMM_WORLD);
	MPI_Bcast(&value->phaseR,1,MPI_FLOAT,0,MPI_COMM_WORLD);
	MPI_Bcast(&value->epsilon,1,MPI_FLOAT,0,MPI_COMM_WORLD);

}
