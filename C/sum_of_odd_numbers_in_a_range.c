#include<stdio.h>
int main()
{
    int start,end,sum=0;
    printf("Enter the range:");
    scanf("%d,%d",&start,&end);
    for(int i=start;i<=end;i++){
        if(i%2!=0){
            printf("%d ",i);
            sum+=i;
        }
    }
    printf("\nSum of all odd number in given range is: %d",sum);
    return 0;
}