#include <stdio.h>

int main(){
	int x, y, i, j;
	
	x = 2;
	y = 3;
	
	for (i = 0; i<5; i++){
		for (j = 0; j<5; j++){
			if(i == y && j == x){
				printf("D");	
			}
			else{
				printf("*");
			}
		}
		printf("\n");
	}
	
	return 0;
}
