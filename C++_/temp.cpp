#include<iostream>
using namespace std;
int RecursiveFunction(int value)
{
    static int temp =0;
    if(value<=0)
        return 1;
    if(value>5)
    {
        temp=value;
        return RecursiveFunction(value-2)+3;
    }
    if(value>2)
    {
        temp=value;
        return RecursiveFunction(value-2)-2;
    }
    return RecursiveFunction(value-1)+temp;
}
int main()
{
    cout<<RecursiveFunction(7);
    cout<<endl;
    cout<<RecursiveFunction(9);
    return 0;
}