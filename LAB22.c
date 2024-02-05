#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int power_minus_one(int n) {
    return (n % 2 == 1) ? 1 : -1;
}

double power_expression( double x, int n) {
    double result = 1.0;
    for (int i = 0; i < 2 * n - 1; ++i) {
        result *= x;

    }

    return result;
}

double series(double x, int numTerms) {
    double sum = 0;

    for (int n = 0; n <= numTerms; n++) {
        double term = power_minus_one(n) *power_expression(x,n)/ (2 * n - 1);
        sum += term;
    }

    return sum;
}

double arctg(double x) {
    return atan(x);
}

int main() {
    double x;
    int numTerms;

    printf("Enter the value of x: ");
    scanf("%lf", &x);

    printf("Enter the number of series terms: ");
    scanf("%d", &numTerms);

    double result = series(x, numTerms);
    double arctg_result = arctg(x);
    printf("Result with %d series terms: %lf\n", numTerms, result);
    printf("arctg(x) result: %lf\n", arctg_result);

    double epsilon = 1e-10;

    if (fabs(result - arctg_result) < epsilon) {
        printf("Series result is approximately equal to arctg(x)\n");
    } else {
        printf("Series result is not equal to arctg(x)\n");
    }

    return 0;
}