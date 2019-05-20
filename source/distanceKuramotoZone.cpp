#include "../include/masterHeader.h"
bool swimmer :: distanceKuramotoZone(swimmer* agent[], const int i, const int j){

	if(i==j) return true;
	float dx = agent[j]->xPosition - xPosition, dy = agent[j]->yPosition - yPosition; 

	if(dx>length*0.5) dx -= length;
	else if(dx<-length*0.5) dx += length;

	if(dx>orienR) return false;

	if(dy>width*0.5) dy -= width;
	else if(dy<-width*0.5) dy += width;

	if(dy>orienR) return false;

	if(viewField == 360) return dx*dx+dy*dy<phaseR*phaseR;

	float angle = atan2(dy,dx);
	angle += (angle<0) ? TwoPi : 0;

	while(orientation > TwoPi)
		orientation -= TwoPi;
	while(orientation < 0)
		orientation += TwoPi;

	return dx*dx+dy*dy<phaseR*phaseR && abs(orientation - angle) <= viewField * 0.5;
}
