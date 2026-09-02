#include <stdio.h>
#include <math.h>

#define EPSILON 0.000001

// Function f(x) = 3x - cos(x) - 1
double f(double x) { 
    return 3.0 * x - cos(x) - 1.0; 
}

// Derivative f'(x) = 3 + sin(x)
double df(double x) { 
    return 3.0 + sin(x); 
}

int main() {
    double a, b, x0, x1;
    int iteration = 0;

    // Finding an interval using Intermediate Value Theorem
    a = 0.0;
    b = 1.0;

    printf("Equation: 3x = cos(x) + 1\n\n");
    printf("f(%.1f) = %.6f\n", a, f(a));
    printf("f(%.1f) = %.6f\n", b, f(b));

    if (f(a) * f(b) < 0) {
        printf("\nSince f(a) and f(b) have opposite signs,\n");
        printf("a real root lies between %.1f and %.1f.\n", a, b);

        // Initial approximation by midpoint
        x0 = (a + b) / 2.0;
        printf("Initial approximation x0 = %.5f\n\n", x0);

        printf("Newton-Raphson Iterations\n");
        printf("Iteration\t x\n");

        do {
            x1 = x0 - f(x0) / df(x0);
            iteration++;
            printf("%d\t\t %.10f\n", iteration, x1);

            // Stop when correct to five decimal places
            if (round(x1 * 100000) == round(x0 * 100000)) {
                break;
            }
            
            x0 = x1;
        } while (iteration < 100);

        printf("\nReal root = %.5f\n", x1);
    } else {
        printf("No root exists in the given interval.\n");
    }

    return 0;
}
