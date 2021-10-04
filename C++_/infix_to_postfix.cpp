#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>
using namespace std;
#define MAX 20
char stack[MAX];
int top=-1;
char pop();
void push(int val);


int prcd(char symbol)
{
switch(symbol)
{
case '+':
case '-':
return 2;
case '*':
case '/':
return 4;
case '^':
case '$':
return 6;
case '(':
case ')':
case '#':
return 1;
}
}


int isoperator(char symbol)
{
switch(symbol)
{
case '+':
case '-':
case '*':
case '/':
case '^':
case '$':
case '(':
case ')':
return 1;
default:
return 0;
}
}

void convertip(char infix[],char postfix[])
{
int i,j=0;
char symbol;
stack[++top]='#';

for(i=0;i<strlen(infix);i++)
{
symbol=infix[i];
if(isoperator(symbol)==0)
{
postfix[j]=symbol;
j++;
}
else
{
if(symbol=='(')
push(symbol);
else if(symbol==')')
{
while(stack[top]!='(')
{
postfix[j]=pop();
j++;
}
pop();
}
else
{
if(prcd(symbol)>prcd(stack[top]))
push(symbol);
else
{
while(prcd(symbol)<=prcd(stack[top]))
{
postfix[j]=pop();
j++;
}
push(symbol);
}
} 
}
}
while(stack[top]!='#')
{
postfix[j]=pop();
j++;
}
postfix[j]='\0'; 
}

int main()
{
char infix[20],postfix[20];
cout<<endl<<"Enter the valid infix string:";
gets(infix);
convertip(infix,postfix);
cout<<endl<<"The corresponding postfix string is:";
puts(postfix);
int i=0;
int a,b,c;
while(postfix[i]!='\0')
{
if(isdigit(postfix[i])||isalpha(postfix[i]))
push(postfix[i]-48);
else if(postfix[i]!=32)
{
a=pop();
b=pop();
if(postfix[i]=='*')
c=b*a;
else if(postfix[i]=='/')
c=b/a;
else if(postfix[i]=='+')
c=b+a;
else if(postfix[i]=='^')
c=pow(b,a);
else
c=b-a;
push(c);
}
i++;
}
cout<<endl<<c;

getch();
return 0;
}

void push(int val)
{
stack[++top]=val;
}
char pop()
{
return stack[top--];
}