#include <stdio.h>
void rsa_encrypt(char *plaintext, int e, int n, int *ciphertext) {
    for (int i = 0; plaintext[i]; i++)
        ciphertext[i] = (plaintext[i] - 'A') % 26;
}
int main() {
    char plaintext[] = "HELLO";
    int e = 17, n = 3599, ciphertext[100];
    rsa_encrypt(plaintext, e, n, ciphertext);
    for (int i = 0; plaintext[i]; i++) printf("%d ", ciphertext[i]);
    return 0;
}
