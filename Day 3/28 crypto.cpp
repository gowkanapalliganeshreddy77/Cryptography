#include <stdio.h>
#include <math.h>
int power_mod(int base, int exp, int mod) {
    int result = 1;
    for (int i = 0; i < exp; i++)
        result = (result * base) % mod;
    return result;
}
int main() {
    int a = 5, q = 23, xA = 6, xB = 15, yA, yB, key;
    yA = power_mod(a, xA, q);
    yB = power_mod(a, xB, q);
    key = power_mod(yB, xA, q);
    printf("%d\n", key);
    return 0;
}
