#include<stdio.h>
int main()
{
    int prin,time,rate;
    float si=0;
    printf("Enter principal amount time and rate respectively");
    scanf("%d,%d,%d",&prin,&time,&rate);
    si=(prin*time*rate)/100;
    printf("Simple intrest is %f",si);
    return 0;
}