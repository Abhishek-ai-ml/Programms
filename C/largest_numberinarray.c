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
    int arr[]={23,6,78,99,56};
    int max=returnmax(arr,5);
    printf("Maximum number in array is:%d",max);
    return 0;
}