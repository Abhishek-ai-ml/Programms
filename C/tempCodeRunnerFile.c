#include<stdio.h>
int main()
{
    int month;
    printf("Enter month number:");
    scanf("%d",&month);
    switch(month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        printf("Number of days:31");
        break;
    
    case 4:
    case 6:
    case 9:
    case 11:
        printf("Number of days: 30");
        break;
    
    case 2:
        printf("Number of days: 28/29");
        break;
    default: printf("Invalid number enter number between 1 to 12");
             break;

    }
    return 0;    

   
}