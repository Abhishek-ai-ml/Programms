#include<stdio.h>

int returnmax(int array[],int n){
    int max=0;
    for(int i=0;i<n;i++){
        if(array[i]>max){
            max=array[i];
        }
    }
    return max;
}
int main()
{
    int arr[10];
    for(int i=0;i<10;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<10;i++){
        printf("%d",arr[i]);
        printf("\n");
    }
    int max=returnmax(arr,10);
    printf("largest number is:%d",max);
    return 0;
}