#include<iostream>
using namespace std;
int main()
{
    int arr[50],low,mid,high,size,num,flag=0;
    cout<<"Enter the size of array:";
    cin>>size;
    if(size>50)
    {
        cout<<"Array maximum limit reached\n";
    }
    else{
    cout<<"Enter elements in array(in ascending form):\n";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    low=0,high=size-1;
    cout<<"Enter the element to searched for: ";
    cin>>num;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(arr[mid]==num)
        {
            cout<<"Element found in array at position: "<<mid+1;
            exit(0);
        }
        else if(arr[mid]<num)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    cout<<"Element not found in array";
    }
    
    return 0;
}