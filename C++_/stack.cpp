#include<iostream>
using namespace std;
int stack[50],n=50,top=-1,choice,value;
void push(int value)
{
    if(top>=n-1)
   cout<<"Stack Overflow"<<endl;
   else {
      top++;
      stack[top]=value;
}
}
void pop()
{
    if(top<=-1)
   cout<<"Stack Underflow"<<endl;
   else {
      cout<<"Element Popped is:"<< stack[top] <<endl;
      top--;
   }
}
void display() {
   if(top>=0) {
      cout<<"Stack elements are:";
      for(int i=top; i>=0; i--)
      cout<<stack[i]<<" ";
      cout<<endl;
   } else
   cout<<"Stack is empty";
}
int main()
{
    cout<<"1. Push\n";
    cout<<"2. Pop\n";
    cout<<"3. Display\n";
    cout<<"4. Exit\n";
    do
    {
        cout<<"Enter Choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:{
                cout<<"Enter the value to be pushed:";
                cin>>value;
                push(value);
                break;
            }
            case 2: {
                pop();
                break;
            }
            case 3: {
                display();
                break;
            }
            case 4: {
                cout<<"Exist";
                break;
            }
            default : cout<<"Invalid Choice\n";
        }
    } while (choice!=4);
    return 0;
    
}