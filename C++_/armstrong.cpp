#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n,temp,sum=0;
    cin>>n;
    temp=n;
    while(temp>0){
        int lastdigit = temp%10;
        sum= sum+pow(lastdigit,3);
        temp=temp/10;
    }
    if(sum==n){
        cout<<"Armstrong"<<endl;
    }
    else{
        cout<<"Not armstrong"<<endl;
    }
    return 0;
}