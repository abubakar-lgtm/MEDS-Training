#include <stdio.h>

double exp_taylor(double x, int terms) {
    double result = 1.0;
    double term = 1.0;

    for (int n = 1; n < terms; ++n) {
        term = term * (x / n); 
        result += term;
    }

    return result;
}

int main() {
    double x = 2.0;
    int terms = 20;

    double result = exp_taylor(x, terms);
    printf("e^%.2f ≈ %.10f\n", x, result);

    return 0;
}
