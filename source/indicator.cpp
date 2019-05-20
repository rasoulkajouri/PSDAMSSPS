#include "../include/functions.h"
void indicator(const int X, const int Y){

	if (X%100==0)
		printf(" %i%% completed\r",X * 100 / Y + 1);
}
