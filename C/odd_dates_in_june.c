#include<stdio.h>
int main()
{   printf("Odd dates in month of june are :\n");
    for(int i=1;i<=30;i++){
        if(i%2!=0){
            printf("%d ",i);
        }
    }
    return 0;
}