#include<stdio.h>
int main()
{
    int n=0;
    printf("Enter the number:");
    scanf("%d",&n);
    printf("Number perfectly divide %d are:",n);
    for(int i=1;i<=n;i++){
        if(n%i==0){
            printf("%d ",i);
        }
    }
    return 0;
}