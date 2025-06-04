#include <stdio.h>

double sqrt_binary_search(double x, double precision) {
    if (x < 0) {
        printf("Error: Negative input.\n");
        return -1;
    }

    if (x == 0 || x == 1)
        return x;

    double low = 0, high = x;
    if (x < 1) high = 1; 

    double mid;
    while ((high - low) > precision) {
        mid = (low + high) / 2;
        double square = mid * mid;

        if (square < x)
            low = mid;
        else
            high = mid;
    }

    return (low + high) / 2;
}

int main() {
    double number = 2.0;
    double precision = 1e-7;

    double result = sqrt_binary_search(number, precision);
    printf("Square root of %.6f ≈ %.10f\n", number, result);

    return 0;
}
