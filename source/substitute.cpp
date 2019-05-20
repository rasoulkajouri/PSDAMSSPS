#include "../include/storeStructure.h"
#include "../include/masterHeader.h"

void swimmer :: substitute(struct store* doer, int i, int c){

	(*doer).xPosArray[c][i] = xPosition;
	(*doer).yPosArray[c][i] = yPosition;
	(*doer).orienArray[c][i] = orientation;
	(*doer).phaseArray[c][i] = phase;
}
