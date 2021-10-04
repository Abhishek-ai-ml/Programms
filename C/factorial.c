#include<stdio.h>
int factorial(int num);
int main()
{
    int n,res;
    printf("Enter the Integer:");
    scanf("%d",&n);
    res=factorial(n);
    printf("The factorial of %d is %d",n,res);
    return 0;
}
int factorial(int n)
    {
    long int fact=1;
    if(n==0||n==1){
        printf("Factorial of given no. is 1");
    }
    else if(n>=2){
        for(int i=n;i>=1;i--){
            fact=fact*i;
        }
        
    }
    return fact;
    }