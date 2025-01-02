#include <stdio.h>

void generate_signature(int message, int k, int q, int *r, int *s, int x) {
    *r = (message * k) % q;
    *s = (x * *r + k) % q;
}

int main() {
    int message = 5, k = 7, q = 23, x = 3, r1, s1, r2, s2;
    generate_signature(message, k, q, &r1, &s1, x);
    generate_signature(message, k + 1, q, &r2, &s2, x);
    printf("%d %d\n%d %d\n", r1, s1, r2, s2);
    return 0;
}
