#include<stdio.h>
int main()
{
    int num,i,c=0;
    printf("Enter a number:");
    scanf("%d",&num);
    for(i=1;i<=num;i++){
        if(num%i==0)
        {
            c++;
        }
    }
    if(c==2)
    {
        printf("The given number is Prime");
    }
    else{
        printf("Given number is not Prime");
    }
    return 0;
}