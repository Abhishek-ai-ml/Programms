#include<stdio.h>
int red(char*);
int green(char *p)
{
    if(*p !='\0')
    {
        printf("%c",*p);
        red(p+1);
        red(p+1);
    }
    return 0;
}
int red(char *p)
{
    if(*p !='\0')
    {
        green(p+1);
        printf("%c", *p);
        green(p+1);
    }
    return 0;
}
int main()
{
    green("RGB");
    return 0;
}