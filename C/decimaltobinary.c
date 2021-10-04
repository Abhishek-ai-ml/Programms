#include<stdio.h>
long decimaltobinary(int);
int main(){
   long bnum;
   int dnum;
   printf(" Enter any decimal number : ");
   scanf("%d",&dnum);
   bnum = decimaltobinary(dnum);
   printf("\n The Binary value is : %ld\n",bnum);
   return 0;
}
long decimaltobinary(int dnum){
   long bnum=0,rem,f=1;
   while(dnum != 0){
      rem = dnum % 2;
      bnum = bnum + rem * f;
      f = f * 10;
      dnum = dnum / 2;
   }
   return bnum;
}