#include<stdio.h>
int main()
{
    int dec, rem=0,bina=0;
    printf("Enter the decimal number:");
    scanf("%d",&dec);
    while(dec>0){
        rem=dec%2;
        bina=bina*10+rem;
        dec=dec/10;
    }
    printf("%d",bina);
    return 0;
}