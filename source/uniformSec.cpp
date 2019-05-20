#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include "uniformSec.h"
//-------------------------------------------------------------------------------------------------------

using namespace std;		//define variables with amounts
const long int a1 = 0x5DEECE66D;
const long int a2 = 0x8088405;
const long int b1 = 0xB;
const long int b2 = 1;
long int iseed=-time(NULL),iiseed;		//we define seed1 here as you suggested
float Buff[256];
//Functions----------------------------------------------------------------------------------------


long int LCG1(long int r){
	long te  = (a1*r+ b1);
	long te2 = (pow(2.0,48) - 1);
	return (te & te2);
	}

long int LCG2(long int r){
	long te  = (a2*r+ b2);
	long te2 = (pow(2.0,48) - 1);
	return (te & te2) ;
	}
//Randomize-Function-------------------------------------------------------------------------------

void Randomize(){

	for (int i=0 ; i<256 ; i++){
		iseed = LCG1(iseed);
		Buff[i] = iseed;
	}

	iseed  = LCG1(iseed);
	iiseed = iseed;
    }



//MyRandom-----------------------------------------------------------------------------------------


float myrandom(){
	iiseed = LCG2(iiseed);
	int x = ( 256.0 * iiseed)/pow(2.0,48);
	int i = x;
	float temp = Buff[i];
	iseed = LCG1(iseed);
	Buff[i] = iseed;
	return (1.0*temp)/pow(2.0,48);

}

//Main---------------------------------------------------------------------------------------------

double uniform_sec(){
	Randomize();

	return myrandom();
}
