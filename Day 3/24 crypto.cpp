#include <stdio.h>

int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int extended_gcd(int a, int b, int *x, int *y) {
    if (!b) {
        *x = 1, *y = 0;
        return a;
    }
    int x1, y1, gcd = extended_gcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - y1 * (a / b);
    return gcd;
}

int main() {
    int e = 31, n = 3599, p = 59, q = 61, phi = (p - 1) * (q - 1), d, x, y;
    if (extended_gcd(e, phi, &x, &y) == 1) d = (x % phi + phi) % phi;
    printf("%d\n", d);
    return 0;
}
