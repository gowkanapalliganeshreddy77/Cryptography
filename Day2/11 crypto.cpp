#include <stdio.h>
#include <math.h>
int factorial(int n) {
    return (n == 0 || n == 1) ? 1 : n * factorial(n - 1);
}
int main() {
    int total_letters = 25; 
    long long total_keys = factorial(total_letters);
    double approx_power_2 = log2(total_keys);
    printf("Ignoring duplicates: Approximate power of 2: %.2f\n", approx_power_2);
    long long unique_keys = total_keys / factorial(5); 
    approx_power_2 = log2(unique_keys);
    printf("Considering unique keys: Approximate power of 2: %.2f\n", approx_power_2);
    return 0;
}
