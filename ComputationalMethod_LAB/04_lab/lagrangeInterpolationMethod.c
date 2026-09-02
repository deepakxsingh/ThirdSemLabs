// to find value of f(f(x)) for a given value of x using lagrange's interpolation method

#include <stdio.h>
double lagrangeInterpolation(double x[], double y[], int n, double value)

{
    double result = 0.0;

    for (int i = 0; i < n; i++)
    {

        double term = y[i];
        for (int j = 0; j < n; j++)
        {

            if (i !=j)
            {
                term*= (value - x[j]) / (x[i] - x[j]);
            }


        }

        result +=term;

    }

    return result;


}


int main()


{


    // Given data points:


    // (1, 1), (2, 4), (3, 9)


    double x[] = {1,2, 3};


    double y[] = {1,4, 9};


    int n = 3;

    // Find y when x = 2.5

    double value = 2.5;


 


    double result = lagrangeInterpolation(x, y, n, value);
   
printf("Interpolated value at x = %.2f is %.4f\n", value, result);


 


    return 0;


}