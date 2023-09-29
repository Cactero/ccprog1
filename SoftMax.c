#include <stdio.h>
float softmax(int nVal1, int nVal2, int nVal3, float fInput){
    float sum = nVal1 + nVal2 + nVal3;
    float percentage = (fInput/sum)*100;
    return percentage;
}

int main(){
    int nVal1, nVal2, nVal3;
    float fInput;

    printf("Input nVal1: ");
    scanf("%d", &nVal1);
    printf("Input nVal2: ");
    scanf("%d", &nVal2);
    printf("Input nVal3: ");
    scanf("%d", &nVal3);
    printf("Input fInput: ");
    scanf("%f", &fInput);

    printf("%.2f%%", softmax(nVal1,nVal2,nVal3,fInput));
    return 0; 
}