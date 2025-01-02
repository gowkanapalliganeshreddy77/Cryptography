#include <stdio.h>
#include <string.h>
#define ALPHABET_SIZE 26
int mod_inverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}
void affine_decrypt(char *ciphertext, int a, int b) {
    int n = strlen(ciphertext);
    int a_inv = mod_inverse(a, ALPHABET_SIZE);  
    if (a_inv == -1) {
        printf("Modular inverse doesn't exist for a = %d\n", a);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            ciphertext[i] = ((a_inv * (ciphertext[i] - 'A' - b + ALPHABET_SIZE)) % ALPHABET_SIZE) + 'A';
        }
    }
    printf("Decrypted text: %s\n", ciphertext);
}
int main() {
    char ciphertext[100];
    int a, b;
    printf("Enter the ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);
    ciphertext[strcspn(ciphertext, "\n")] = 0;
    printf("Enter the value of a: ");
    scanf("%d", &a);
    printf("Enter the value of b: ");
    scanf("%d", &b);
    affine_decrypt(ciphertext, a, b);
    return 0;
}
