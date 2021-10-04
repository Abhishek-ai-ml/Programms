#include<iostream>
using namespace std;
void count(int n){
    if(n<=0)
        return;
    cout<<n<<endl;
    return count(n-1);
}
void count_1(int n){
    if(n<=0)
        return;
     count_1(n-1);
    cout<<n<<endl;
}
int main()
{
    int n,n_1;
    cout<<"Enter the number:";
    cin>>n;
    /* cout<<"Enter the second number:";
    cin>>n_1; */
    count(n);
    cout<<endl;
    count_1(n);
    return 0;
}