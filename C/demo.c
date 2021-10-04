#include<stdio.h>
int main(){
  int a=10;
  int b=20;
  int *p1= &a;
  int *p2= &b;
  swap(&p1,&p2);
  return 0;
}
void swap(int **p1, int **p2)
{
  int **temp;
  *temp=*p1;
  *p1=*p2;
  *p2=*temp;
}