#include<stdio.h>
int main()
{
    int n,a[100];
    printf("Enter the size of array:");
    scanf("%d",&n);
    printf("Enter the elements in array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("Array is:");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}