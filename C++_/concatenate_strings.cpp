#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	
	char str1[100];
	char str2[100];
	cout<<"Enter first string : "<<endl;
	cin.getline(str1,100);
	cout<<"Enter second string : "<<endl;
	cin.getline(str2,100);
	int i, j;
	for(i=0; str1[i] != '\0'; i++)
	{
		;
	}
	
	for(j=0; str2[j] != '\0'; j++,i++)
	{
		str1[i]=str2[j];
	}
	str1[i]='\0';
	cout<<"Concatenated string is: ";
	cout<<str1<<endl;
	return 0;
}
