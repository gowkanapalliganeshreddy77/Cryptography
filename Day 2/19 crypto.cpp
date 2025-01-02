#include <stdio.h>
void cbc_encrypt(char plaintext[], char key1[], char key2[], char iv[]) {
    for (int i = 0; plaintext[i]; i++)
        plaintext[i] ^= key1[i % 8] ^ key2[i % 8] ^ iv[i % 8];
}
int main() {
    char plaintext[100], key1[8], key2[8], iv[8];
    cbc_encrypt(plaintext, key1, key2, iv);
    return 0;
}
