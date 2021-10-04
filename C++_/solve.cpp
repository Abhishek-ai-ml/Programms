#include<iostream>
using namespace std;
int main()
{
    float temp=298.0;
    for(int i=1;i<=15;i++){
        float res=1000.0/temp;
        temp+=5;
        cout<<res<<endl;
    }
    return 0;
}