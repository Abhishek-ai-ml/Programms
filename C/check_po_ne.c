#include<stdio.h>
int main()
{
    int num,psum=0,nsum=0,zsum=0;
    char ch='y';
    do{
        printf("Enter the number:");
        scanf("%d",&num);
        if(num>0)
            psum++;
        else if(num<0)
            nsum++;
        else if(num==0)
            zsum++;
        printf("Enter number?\nPress n to exit\n");
        scanf("%c",&ch);    
    }while(ch!='n');

    printf("Count of positive number is:%d\n",psum);
    printf("Count of negative number is:%d\n",nsum);
    printf("Count of zero is:%d\n",zsum);
    return 0;
}