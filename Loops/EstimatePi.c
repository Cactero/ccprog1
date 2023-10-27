#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int nCountPtInCr, nTries, i;
	double fx, fy;
	srand(10);
	nCountPtInCr = 0;
	nTries = 1000000;
	
	for(i = 0; i<nTries; i++){
		fx = rand()/(RAND_MAX*1.0);
		fy = rand()/(RAND_MAX/1.0);
		if(sqrt(pow(fx,2) + pow(fy,2)) <= 1)
			nCountPtInCr++;
	}
	
	printf("%.15f", 4*(nCountPtInCr/(nTries*1.0)));
	return 0;
}
