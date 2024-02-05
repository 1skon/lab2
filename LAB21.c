#include <stdio.h>
#include <math.h>
#include <stdlib.h>
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
double model (double term){
    if (term<0){
        term*=(-1);
    }
    return term;
}

double series(double x, double eps) {
    double sum = 0;
    int n=0;
    double term = 1;
    while (model(term)>eps) {
        n++;
        sum += term;
        term = power_minus_one(n) *power_expression(x,n)/ (2 * n - 1);;
    }
    printf("terms quantity %d\n",n);
    return sum;
}


double arctg(double x) {
    return atan(x);}

int main() {
    double x;
    double eps;

    printf("Enter the value of x: ");
    scanf("%lf", &x);

    printf("Enter the eps ");
    scanf("%lf", &eps);

    double result = series(x, eps);
    double arctg_result = arctg(x);
    printf("Result with %lf series terms: %lf\n", eps, result);
    printf("arctg(x) result: %lf\n", arctg_result);

    if (result > arctg_result) {
        printf("Series result is greater than arctg(x)\n");
    } else if (result < arctg_result) {
        printf("Series result is less than arctg(x)\n");
    } else {
        printf("Series result is equal to arctg(x)\n");
    }

    return 0;
}
