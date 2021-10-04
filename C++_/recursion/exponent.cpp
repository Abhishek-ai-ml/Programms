#include<iostream>
using namespace std;
int exp(int n){
    if(n==0)
        return 1;
    int answer = exp(n/2);
    if(n&1){
        return 2*answer*answer;
    }
    else
    {
        return answer*answer;
    }
}
int main()
{
    int num;
    cout<<"Enter the power of exponent : ";
    cin>>num;
    int ans = exp(num);
    cout<<"2 to the power "<<num<<" is "<<ans;
    return 0;
}