#include<stdio.h>
int main()
{
    int i,j,c=0;
    printf("Prime numbers between 2 to 100 are:\n");
    for(i=2;i<=100;i++)
    {
        for( j=1;j<=i;j++)
        {
            if(i%j==0)
                c++;
        }
        if(c==2)
            printf("%d ",i);
        c=0;
    }
    
    return 0;
}