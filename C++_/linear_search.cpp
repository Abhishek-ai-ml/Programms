#include<iostream>
using namespace std;
int main()
{
    int arr[50],size,element,flag;
    cout<<"Enter the size of array:";
    cin>>size;
    if(size>50)
    {
        cout<<"Array maximum limit reached\n";
    }
    else
    {
    cout<<"Enter Elements in array:\n";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter element to searched:";
    cin>>element;
    cout<<"SEARCHING.....\n";
    for(int i=0;i<size;i++)
    {
        if(arr[i]==element)
        {
            cout<<"Element Found in the array at position:\t"<<i+1<<endl;
            flag=1;
        }
        
    }
    if(flag!=1)
    {
        cout<<"Element not found in array:";
    }
    }
    return 0;
}