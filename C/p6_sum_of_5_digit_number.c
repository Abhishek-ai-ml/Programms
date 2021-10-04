#include<stdio.h>
int main()
{
    int num,temp,last_digit,sum=0;
    printf("Enter the number:");
    scanf("%d",&num);
    temp=num;
    while(temp>0)
    {
       last_digit=temp%10;
       sum=sum+last_digit;
       temp=temp/10;
    }
    printf("%d",sum);
    return 0;

}