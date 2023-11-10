#include <stdio.h>

int nthFibonacci(int nth){
	int i;
	int x = 1;
	int y = 1;
	int result = 0;
	if(nth == 1 || nth == 2)
		result = 1;
	else if(nth>2){
		for(i=0; i<nth; i++){
			x = y;
			y = result;
			result = x + y;
		}
	}
	return result;
}

int main(){
	int userInput;
	printf("Enter the nth term of the fibonacci sequence: ");
	scanf("%d", &userInput);
	printf("%d", nthFibonacci(userInput));
	return 0;
}
