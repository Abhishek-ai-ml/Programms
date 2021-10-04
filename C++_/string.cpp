#include<iostream>
using namespace std;
int main()
{
    string str1,str2;
    int i,j,len1=0,len2=0,len3=0,pos;
    cout<<"Enter main string:";
    getline(cin,str1);
    for(int i=0;str1[i];i++)
    {
        len1++;
    }
    cout<<"Enter substring:";
    getline(cin,str2);
    for(int i=0;str2[i];i++)
    {
        len2++;
    }
    for (i = 0; str1[i]; i++)
    {
        j = 0;
        if (str1[i] == str2[j])
        {
            pos=i;
            while (str1[i] == str2[j])
            {
                i++;
                j++;
            }

            if (str2[j] == '\0')
            {
                cout << "The substring is present in main string at position "<<pos<<"\n";
                string str3;
                cout << "Enter the string to replace substring : "<<endl;
                getline(cin, str3);
                for(int i=0;str3[i];i++)
                    {
                        len3++;
                    }
                if(len2!=len3)
                {
                    cout<<"Error!! String are not of same length\n";
                }
                else
                {
                for (int i = 0; i < len3; i++)
                {
                    str1[pos]=str3[i];
                    pos++;
                }
                cout<<"Updated String is : "<<str1;
                break;
                }
            }
            else
            {
                i = pos;
                pos=0;
            }
        
        }
    }

    if (pos==0)
        cout << "Substring not present in main string\n";

    return 0;
}
