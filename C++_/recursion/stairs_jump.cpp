#include<iostream>
using namespace std;
int numberofjumps(int n){
    if(n<0)
        return 0 ;
    if(n==0)
        return 1;
    return numberofjumps(n-1)+numberofjumps(n-2)+numberofjumps(n-3);
}
int main()
{
    int n;
    cout<<"Enter the highest stairs : ";
    cin>>n;
    int answer = numberofjumps(n);
    cout<<"Number of Ways are : "<<answer;
    return 0;
}