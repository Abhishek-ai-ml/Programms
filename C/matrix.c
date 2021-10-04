#include<stdio.h>
int main()
{
    int n[3][3];
    printf("Enter numbers:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&n[i][j]);
        }
    }

    printf("Matrix is:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",n[i][j]);
        }
        printf("\n");
    }
    return 0;

}