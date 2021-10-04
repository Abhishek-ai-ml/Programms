#include<iostream>
using namespace std;
int main()
{
    int arr[50],pos,size;
    cout<<"Enter the size of array:";
    cin>>size;
    if(size>50)
    {
        cout<<"Array maximum limit reached\n";
    }
    else
    {
    cout<<"Enter the Elements in array:\n";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the position of element to be deleted:";
    cin>>pos;
    if(pos<0||pos>size)
    {
        cout<<"Element cannot be deleted:\n";
    }
    else
    {
    for(int i=pos-1;i<size-1;i++)
    {
        arr[i] = arr[i+1];
    }
    size--;
    cout<<"Updated array after deletion:\t";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    }
    }
    return 0;
}