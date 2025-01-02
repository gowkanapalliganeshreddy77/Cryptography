#include <stdio.h>
#include <string.h>

void cbc_encrypt(char *plaintext, char *key, char *iv, char *ciphertext) {
    for (int i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = (plaintext[i] ^ iv[i % strlen(iv)]) ^ key[i % strlen(key)];
        iv[i % strlen(iv)] = ciphertext[i];
    }
}

int main() {
    char plaintext[] = "HELLO";
    char key[] = "12345678";
    char iv[] = "INITVECT";
    char ciphertext[100];
    cbc_encrypt(plaintext, key, iv, ciphertext);
    printf("%s\n", ciphertext);
    return 0;
}
