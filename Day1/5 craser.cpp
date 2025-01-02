#include <stdio.h>
#include <ctype.h>
#define MOD 26
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
void affine_encrypt(char text[], int a, int b) {
    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            text[i] = ((a * (text[i] - base) + b) % MOD) + base;
        }
    }
}
int main() {
    char text[100];
    int a, b;
    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter a (must be coprime with 26): ");
    scanf("%d", &a);
    if (gcd(a, MOD) != 1) {
        printf("Invalid 'a'. It must be coprime with 26.\n");
        return 1;
    }
    printf("Enter b: ");
    scanf("%d", &b);
    affine_encrypt(text, a, b);
    printf("Ciphertext: %s\n", text);
    return 0;
}
