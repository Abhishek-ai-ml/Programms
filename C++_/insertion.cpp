#include<iostream>
using namespace std;
int main()
{
    int arr[10],size,pos,num;
    cout<<"Enter the size of array:";
    cin>>size;
    if(size>10){
        cout<<"Array size maximum limit reach"<<endl;
    }
    else
    {
    cout<<"Enter the elements in array\n";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"Enter the Number to insert in array:";
    cin>>num;
    cout<<"Enter the position:";
    cin>>pos;
    if(pos>size+1||pos<0){
        cout<<"Number cannot inserted:";
    }
    else
    {
    for(int i=size-1;i>=pos-1;i--){
        arr[i+1]=arr[i];
    }
    arr[pos-1]=num;
    size++;
    cout<<"Updated array is:"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    }
    }
    return 0;
}