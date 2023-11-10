#include <stdio.h>

void printTriangle(int n){
    int row, space, starsAmt;
    for(row=1; row<=n; row++){
        for(space=0; space<n-row; space++){
            printf(" ");
        }
        for(starsAmt=0; starsAmt<row*2-1; starsAmt++){
            printf("*");
        }
        printf("\n");
    }
}

int main(){
    int userInput;
    printf("Make a triangle! ");
    scanf("%d", &userInput);
    printTriangle(userInput);
    return 0;
}
