#include <stdio.h>

void doSomething(int nValue1, int *nValue2)
{ if (nValue1 < 3)
    *nValue2 = *nValue2 +1;
    else 
        *nValue2 = *nValue2 -1;
}

void printSomething (int x, int y, int z)
{ 
    doSomething (y, &x);

    if (x == 0)
        printf("**\n");
    else
        if (x % 2 == 0)
            printf("^%c*-\n",'b');
    doSomething (z, &y);

    if (x!=y)
        printf("*%c*-\n", 'a');
    else if (x == z-y-1) { 
        doSomething (y, &z);
        printf ("-%d-\n", z);
    }
}

int main(){
    int x, y, z;

    x = 0; y = 0; z = x = 1;

    y = x; z += 2;
    printSomething(x, y, z);
    switch (x) { 
        case 0: x+=2; printSomething (x, y, z);
        case 1: doSomething(x, &y);
        case 2: printSomething (x, y, z);break;
        case 3: printSomething (x-3, y, z); break;
        default: doSomething(x, &z); break;
    }

    printf("***%d%d%d***\n", x, y, z);
    if (!(z-3)) { 
        y = 2* y + z % 1 / x;
        doSomething (x, &y);
        printf("*%d*\n",y);
    }
    else{ 
        x = x-1; y = y+1;z = z +3;
        doSomething (z, &x);
        printf("*%d%d*\n",x, y);
    }
    printf("***%d%d%d***\n", x, y, z);
    
    return 0;
    }
