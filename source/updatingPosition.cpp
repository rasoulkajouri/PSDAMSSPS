#include "../include/masterHeader.h"

void swimmer :: updatingPosition(){

	xPosition += dtime * speed * cos(orientation);
	yPosition += dtime * speed * sin(orientation); 


	if (xPosition>length)
		xPosition -= length;
	else if (xPosition< 0)
		xPosition += length;

	if (yPosition >width)
		yPosition -=  width;
	else if (yPosition< 0)
		yPosition +=  width;
}
