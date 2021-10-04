#include<stdio.h>
int main()
{
    int num,temp,last_digit,sum=0,temp2=0;
    printf("Enter the number:");
    scanf("%d",&num);
    temp=num;
    while(temp>0)
    {
       last_digit=temp%10;
       temp2=temp2*10+last_digit;
       temp=temp/10;
    }
    printf("Reverse is:%d",temp2);
    if(temp2==num)
        printf("\nGiven number and its reverse are equal\n");
    else
        printf("\nGiven number and its reverse are not equal\n");

    return 0;

}