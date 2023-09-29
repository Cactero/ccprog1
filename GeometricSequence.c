#include <stdio.h>
int fisGeometric(int nVal1, int nVal2, int nVal3, int nVal4){
    return nVal4/nVal3 == nVal3/nVal2 && nVal3/nVal2 == nVal2/nVal1;
}

int main(){
    int nInput1, nInput2, nInput3, nInput4;
    printf("Input nInput1: ");
    scanf("%d", &nInput1);
    printf("Input nInput2: ");
    scanf("%d", &nInput2);
    printf("Input nInput3: ");
    scanf("%d", &nInput3);
    printf("Input nInput4: ");
    scanf("%d", &nInput4);

    printf("%d", fisGeometric(nInput1, nInput2, nInput3, nInput4));
    return 0;
}
