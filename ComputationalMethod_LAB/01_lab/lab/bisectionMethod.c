#include <stdio.h>

double f(double x) {
    return x*x*x - 4*x - 9;
}

int main() {
    double a = 2, b = 3, mid;
    int n;

    printf("Enter number of iterations: ");
    scanf("%d", &n);

    printf("\n%-6s %-12s %-12s %-12s %-12s\n",
           "Iter", "a", "b", "mid", "f(mid)");
    printf("-----------------------------------------------------------------\n");

    for (int i = 1; i <= n; i++) {
        mid = (a + b) / 2;

        printf("%-6d %-12.6f %-12.6f %-12.6f %-12.6f\n",
               i, a, b, mid, f(mid));

        if (f(a) * f(mid) < 0)
            b = mid;
        else
            a = mid;
    }

    printf("\nApproximate root after %d iterations = %.6f\n", n, mid);

    return 0;
}