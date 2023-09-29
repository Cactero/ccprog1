/*
    Name: Ryan June M. Gemal
    Section: S17
    Item: Palindrome
*/
#include <stdio.h>
int getPalindrome(int num){
    int digit1 = num/1000;
    int digit2 = num/100%10;
    int digit3 = num/10%10;
    int digit4 = num%10;

    int palindrome = digit4*1000 + digit3*100 + digit2*10 + digit1;
    return num == palindrome;
}
int main(){
    int userInput;
    printf("Input a 4-digit integer: ");
    scanf("%d", &userInput);
    printf("%d", getPalindrome(userInput));
    return 0;
}