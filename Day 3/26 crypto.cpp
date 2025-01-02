#include <stdio.h>
int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void generate_new_keys(int e, int phi, int *new_e, int *new_d) {
    for (*new_e = 2; *new_e < phi; (*new_e)++) {
        if (gcd(*new_e, phi) == 1) break;
    }
    for (*new_d = 1; (*new_e * *new_d) % phi != 1; (*new_d)++);
}
int main() {
    int e = 31, p = 59, q = 61, phi = (p - 1) * (q - 1), new_e, new_d;
    generate_new_keys(e, phi, &new_e, &new_d);
    printf("%d %d\n", new_e, new_d);
    return 0;
}
