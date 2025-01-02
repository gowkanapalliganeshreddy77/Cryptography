#include <stdio.h>
#include <string.h>

void cbc_encrypt(char *plaintext, char *key, char *iv, char *ciphertext) {
    for (int i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = (plaintext[i] ^ iv[i % strlen(iv)]) ^ key[i % strlen(key)];
        iv[i % strlen(iv)] = ciphertext[i];
    }
}

void cbc_decrypt(char *ciphertext, char *key, char *iv, char *plaintext) {
    for (int i = 0; i < strlen(ciphertext); i++) {
        plaintext[i] = (ciphertext[i] ^ key[i % strlen(key)]) ^ iv[i % strlen(iv)];
        iv[i % strlen(iv)] = ciphertext[i];
    }
}

int main() {
    char plaintext[] = "HELLO";
    char key[] = "12345678";
    char iv[] = "INITVECT";
    char ciphertext[100], decrypted[100];
    cbc_encrypt(plaintext, key, iv, ciphertext);
    cbc_decrypt(ciphertext, key, iv, decrypted);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted: %s\n", decrypted);
    return 0;
}
