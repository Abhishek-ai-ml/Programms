#include<stdio.h>
int main()
{
    int num, sum=0;
    printf("Enter the Number:");
    scanf("%d",&num);
    sum=(num*(num+1))/2;
    printf("sum of first %d natural number is %d",num,sum);
    return 0;
}