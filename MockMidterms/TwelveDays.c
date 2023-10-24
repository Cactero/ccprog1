#include <stdio.h>

int main(){
    int day;

    printf("Enter day: ");
    scanf("%d", &day);
    
    if(day == 1){
        printf("On the 1st day of Christmas, my true love sent to me: \n");
    }
    else if(day == 2){
        printf("On the 2nd day of Christmas, my true love sent to me: \n");
    }
    else if(day == 3){
        printf("On the 3rd day of Christmas, my true love sent to me: \n");
    }
    else{
        printf("On the %dth day of Christmas, my true love sent to me: \n", day);
    }

    switch(day){
        case 12:
            printf("Twelve drummers drumming\n");
        case 11:
            printf("Eleven pipers piping\n");
        case 10:
            printf("Ten lords leaping\n");
        case 9:
            printf("Nine ladies dancing\n");
        case 8:
            printf("Eight maids a-milking\n");
        case 7:
            printf("Seven swans a-swimming\n");
        case 6:
            printf("Six geese a-laying\n");
        case 5:
            printf("Five golden rings\n");
        case 4:
            printf("Four calling birds\n");
        case 3:
            printf("Three french hens\n");
        case 2:
            printf("Two turtle doves and\n");
        case 1:
            printf("A partridge in a pear tree\n");
    }
    return 0;
}
