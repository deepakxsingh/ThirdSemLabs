#include <stdio.h>
#include <math.h>
#define e 0.001
#define f(x) pow(x,3)-2*x-5
int main(){
int i = 0;
float x0, x1, x2, f0, f1, f2;
printf("Enter the value of x0 and x1 : ");
scanf("%f%f", &x0 , &x1);
do{
f0 = f(x0);
f1 = f(x1);
if(f0 == f1){
printf("Mathematical Error."); 
return 0;
}
x2 = ((x0*f1)-(x1*f0))/(f1-f0);
f2 = f(x2);
x0 = x1;
f0 = f1;
x1 = x2;
f1 = f2;
++i;
printf("No of iteration : %d\t", i);
printf("Root = %f\t", x2);
printf("Value of fn = %f\n", f2);
}while(fabs(f2)>e);
printf("\nRoot is: %f\n", x2);
return 0;
}
