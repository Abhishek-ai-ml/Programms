#include<stdio.h>
int main()
{
    int arr[10],sum=0;
    printf("Enter numbers:");
    for(int i=1;i<=10;i++){
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }
    float average = sum/10.0;
    printf("Sum of 10 numbers: %d\n",sum);
    printf("Average of numbers is: %f",average);
    return 0;
}