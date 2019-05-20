#include "../include/masterHeader.h"
#include "../include/functions.h"
#include "../include/masterStructure.h"
#include "../include/storeStructure.h"
#include "../include/measurmentStructure.h"

float *phaseTemp, *orientationTemp;

int main(int argc, char* argv[]){

	int idCore, numCores, iErr;
	// Initialize MPI
	iErr = MPI_Init (&argc, &argv);

	if ( iErr != 0 ){
		message(4);
		return EXIT_FAILURE;
  }
	// Get the number of processes.
	iErr = MPI_Comm_size (MPI_COMM_WORLD, &numCores);
	// Get the indivisual process ID.
	iErr = MPI_Comm_rank (MPI_COMM_WORLD, &idCore);

	MPI_Status status;

  struct gate value;
	if (idCore == 0){
		if ( argc >= 2 && atoi(argv[1]) == 1) message(0);

		if ( argc == 3 && atoi(argv[2]) == 1){ message(1); value.getValue();
		}else if (argc == 3 && atoi(argv[2]) == 0)	value.getValueFile();
		else{ message(3); return EXIT_FAILURE;}
		value.display();
	}

	broadcastingStructureValue(&value);

	swimmer *agent[value.number];
	for(int i=0;i<value.number;i++)
		agent[i] = new swimmer(value.number,value.length,value.width,value.timeSeries,value.noise,value.coupling,value.dtime,
												value.mean,value.variance,value.orienR,value.phaseR,value.viewField, value.epsilon, value.speed);

	value.limitation(idCore, numCores);
	phaseTemp = new float [value.stock];
	orientationTemp = new float [value.stock]; 
	
	if (idCore == 0) for(int i=0;i<value.number;i++) agent[i] -> initialization();

	for(int i=0;i<value.number;i++) agent[i] -> broadcastingAngularVelocity();	

  MPI_Barrier(MPI_COMM_WORLD);	

	struct store doer(value.tSteps, value.number);
	struct measurment order (value.tSteps, value.number);

	for (int tnumerator=0;tnumerator<value.tSteps;tnumerator++){

		if(idCore==0){
			indicator(tnumerator, value.tSteps);
			for (int i=0;i<value.number;i++){ 
				agent[i] -> orderParameter(&order);
				agent[i] -> substitute(&doer,i,tnumerator);
			}
		}
		for(int i=0;i<value.number;i++)	agent[i] -> broadcasting();
		
		for (int i=value.startPoint, C=0;i<value.endPoint;i++, C++) 
			agent[i] -> allocation(C, phaseTemp, orientationTemp);

		for (int i=value.startPoint, C=0;i<value.endPoint;i++,C++) 
			agent[i] -> timeEvolution(agent, phaseTemp, orientationTemp, C, i);

		if(idCore==0){
			order.storing(tnumerator);
			receving(numCores, value, agent, phaseTemp, orientationTemp);
			for(int i=0;i<value.number;i++) agent[i] -> updatingPosition();
		}else{
			sending(value, phaseTemp, orientationTemp);
		}
		MPI_Barrier(MPI_COMM_WORLD);	
	}

	if(idCore==0){
		message(5); order.printOrderParameter(value.dtime);
		message(6); order.susceptibility();	
		message(7); doer.printPosition();
		message(8); value.report();
	}

	printf("\n id: %i finished.\n",idCore);
	MPI_Finalize();
  return EXIT_SUCCESS;
}
