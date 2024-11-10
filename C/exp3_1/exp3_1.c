#include <stdio.h>

double calculate_S(int n) {
    double S = 0.0;
    double numerator_prev = 1.0, numerator = 2.0;
    double denominator_prev = 1.0, denominator = 1.0;
    int sign = 1;

    for (int i = 1; i <= n; i++) {
        double term = sign * (numerator / denominator);
        S += term;

        double next_numerator = numerator + numerator_prev;
        numerator_prev = numerator;
        numerator = next_numerator;

        double next_denominator = denominator + denominator_prev;
        denominator_prev = denominator;
        denominator = next_denominator;

        sign = -sign;
    }

    return S;
}

int main() {
    int n_values[] = {2, 8, 13, 14, 15, 16, 19, 20, 199, 200};
    int num_values = sizeof(n_values) / sizeof(n_values[0]);

    for (int i = 0; i < num_values; i++) {
        int n = n_values[i];
        double S = calculate_S(n);
        printf("当 n = %d 时, S = %f\n", n, S);
    }

    return 0;
}