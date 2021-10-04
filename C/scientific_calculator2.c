
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int addition();
int subtraction();
int division();
int multiplication();
int square();
int squareroot();
int power();
int cube();
int cuberoot();
int fraction();
int fraction_power();
int ten_power();
int factorial();
int modulus();
int function_tan();
int function_sin();
int function_cos();
int function_cosec();
int function_sec();
int function_log();




int main(){
    printf("\t\tWelcome to the scientific calculator!!\n\n");
    int choice;
    printf("\n******* Press 0 to quit the program ********\n");
    printf("Enter 1 for Addition \n");
    printf("Enter 2 for Subtraction \n");
    printf("Enter 3 for Division \n");
    printf("Enter 4 for Multiplication \n");
    printf("Enter 5 for Square\n");
    printf("Enter 6 for Square Root \n");
    printf("Enter 7 for Power \n");
    printf("Enter 8  for Cube \n");
    printf("Enter 9  for Cube Root \n");
    printf("Enter 10 for 1/X\n");
    printf("Enter 11 for X^(1/Y)\n");
    printf("Enter 12 for 10^X\n");
    printf("Enter 13 for Factorial\n");
    printf("Enter 14 for Modulus\n");
    printf("Enter 15 for Tan(X)\n");
    printf("Enter 16 for Sin(X)\n");
    printf("Enter 17 for Cos(X)\n");
    printf("Enter 18 for Cosec(X)\n");
    printf("Enter 19 for Sec(X)\n");
    printf("Enter 20 for Log(X)\n");
    
    while(1){    
    printf("\n\nEnter the operation you want to do: ");
    
    scanf("%d",&choice);
            
    switch(choice)
    {
                case 1:
                    addition();
                    break;
                case 2:
                    subtraction();
                    break;
                case 3:
                    division();
                    break;
                case 4:
                    multiplication();
                    break;
                case 5:
                    square();
                    break;
                case 6:
                    squareroot();
                    break;
                case 7:
                    power();
                    break;
                case 8:
                    cube();
                    break;
                case 9:
                    cuberoot();
                    break;
                case 10:
                    fraction();
                    break;
                case 11:
                    fraction_power();
                    break;
                case 12:
                    ten_power();
                    break;
                case 13:
                    factorial();
                    break;
                case 14:
                    modulus();
                    break;
                case 15:
                    function_tan();
                    break;
                case 16:
                    function_sin();
                    break;
                case 17:
                    function_cos();
                    break;
                case 18:
                    function_cosec();
                    break;
                case 19:
                    function_sec();
                    break;
                case 20:
                    function_log();
                    break;        
                case 0:
                    exit(0);
                default:
                    printf("Invalid Operator\n");
        }
    
    }
    return 0;
}

int addition(){
    printf("Enter the numbers you want to add: ");
    int a,b;
    scanf("%d%d",&a,&b);
    printf("The sum of a and b is %d\n",a+b);
}
int subtraction(){
    printf("Enter the numbers you want to subtract: ");
    int a,b;
    scanf("%d%d",&a,&b);
    printf("The subtraction of a and b is %d\n",a-b);
}
int division(){
    printf("Enter the numbers you want to divide: ");
    int a,b;
    scanf("%d%d",&a,&b);
    printf("The division of a and b is %f\n",(float)a/(float)b);
}
int multiplication(){
    printf("Enter the numbers you want to multiply: ");
    int a,b;
    scanf("%d%d",&a,&b);
    printf("The multiplication of a and b is %d\n",a*b);
}
int square(){
    double b;
    printf("Enter the number you want the square of: ");
    scanf("%lf",&b);
    double p=pow(b,2);
    printf("The square of %lf is %lf",b,p);
}
int squareroot(){
    double b;
    printf("Enter the number you want the square root of : ");
    scanf("%lf",&b);
    double s = sqrt(b);
    printf("The square root of %lf is %lf",b,s);
}
int power(){
    double b;
    double p;
    printf("Enter the base and the power: ");
    scanf("%lf%lf",&b,&p);
    double e=pow(b,p);
    printf("The power is %lf",e);
}
int cube(){
    double b;
    printf("Enter the number you want the cube of: ");
    scanf("%lf",&b);
    double p=pow(b,3);
    printf("The cube of %lf is %lf",b,p);
}
int cuberoot(){
    float n;
    printf("Enter the number:");
    scanf("%f",&n);
    printf("Cuberoot of %f is %f:",n,pow(n,(1/3)));
}
int fraction(){
    float n;
    float res;
    printf("Enter the number:\n");
    scanf("%f",&n);
    res=1/n;
    printf("Fraction of %f is %f",n,res);
}
int fraction_power(){
    double x;
    double y;
    printf("Enter the base and the power: ");
    scanf("%lf%lf",&x,&y);
    double e=pow(x,(1/y));
    printf("The power is %lf",e);
}
int ten_power(){
    double p;
    printf("Enter the power: ");
    scanf("%lf",&p);
    double e=pow(10,p);
    printf("The power is %lf",e);
}
int factorial(){
    int n,factorial;
    printf("Enter the number you want the factorial of: ");
    scanf("%d",&n);
    factorial=1;
    for(int i=1;i<=n;i++){
        factorial=factorial*i; // factorial*=i;
    }
    printf("\nFactorial of %d is %d",n,factorial);
}
int modulus(){
    printf("Enter the numbers you want to find modulus of: ");
    int a,b;
    scanf("%d%d",&a,&b);
    printf("The modulus of a and b is %d\n",a%b);
}
int function_tan(){
    printf("Enter number:");
    float n;
    scanf("%f",&n);
    printf("Tan(%f) is:%f",n,tan(n));
    return 0;
}
int function_sin(){
    printf("Enter number:");
    float n;
    scanf("%f",&n);
    printf("Sin(%f) is:%f",n,sin(n));
    return 0;
}
int function_cos(){
    printf("Enter number:");
    float n;
    scanf("%f",&n);
    printf("Cos(%f) is:%f",n,cos(n));
    return 0;
}
int function_cosec(){
    printf("Enter number:");
    float n;
    scanf("%f",&n);
    float res = sin(n);
    printf("Cosec(%f) is:%f",n,(1/res));
    return 0;
}
int function_sec(){
    printf("Enter number:");
    float n;
    scanf("%f",&n);
    float res= cos(n);
    printf("Sec(%f) is:%f",n,(1/res));
    return 0;
}
int function_log(){
    printf("Enter the Number:");
    float n;
    scanf("%f",&n);
    printf("Log of Number is: %f\n",log(n));
    return 0;
}


