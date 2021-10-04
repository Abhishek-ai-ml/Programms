#include<stdio.h>
int main()
{
    int n1,n2,ch=0;
    printf("Enter numbers to perform operation:\n");
    scanf("%d,%d",&n1,&n2);
    do{
        printf("CALCULATOR OPERATION MENU:\n");
        printf("1. ADDITION\n");
        printf("1. SUBTRACTION\n");
        printf("1. DIVISION\n");
        printf("1. MULTIPLICATION\n");
        printf("1. SQUARE\n");
        printf("1. SQUARE ROOT\n");
        printf("1. POWER\n");
        printf("1. CUBE\n");
        printf("1. CUBE ROOT\n");
        printf("1. 1/X\n");
        printf("1. X^(1/Y)\n");
        printf("1. 10^X\n");
        printf("1. MODULUS\n");
        printf("1. TAN(X)\n");
        printf("1. SIN(X)\n");
        printf("1. COS(X)\n");
        printf("1. COSEC(X)\n");
        printf("1. SEC(X)\n");
        printf("1. LOG(X)\n");

        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("%d",n1+n2);
                    break;
            case 2: printf("%d",n1-n2);
                    break;
            case 3: printf("%d",n1/n2);
                    break;
            case 4: printf("%d",n1*n2);
                    break;
            case 5: printf("")
        }
    }

}