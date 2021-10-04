#include<iostream>
using namespace std;
void spell(int n, string str[]){
    if(n==0)
        return;
    spell(n/10,str);
    int number=n%10;
    cout<<str[number]<<" ";
}
int main()
{
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    string str[10] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    cout<<"Answer : ";
    spell(n,str);
    return 0;
}