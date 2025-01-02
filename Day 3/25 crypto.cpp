#include <stdio.h>
int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
    int n = 3599, known_plaintext = 59, factor;
    factor = gcd(n, known_plaintext);
    printf("%d\n", factor);
    return 0;
}
