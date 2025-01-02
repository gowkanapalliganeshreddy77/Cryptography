#include <stdio.h>
#include <string.h>

void des_encrypt(char *plaintext, char *key, char *ciphertext) {
    for (int i = 0; i < 8; i++)
        ciphertext[i] = plaintext[i] ^ key[i];
}

void des_decrypt(char *ciphertext, char *key, char *plaintext) {
    for (int i = 0; i < 8; i++)
        plaintext[i] = ciphertext[i] ^ key[i];
}

int main() {
    char plaintext[9] = "ABCDEFGH", key[9] = "12345678", ciphertext[9], decrypted[9];
    des_encrypt(plaintext, key, ciphertext);
    des_decrypt(ciphertext, key, decrypted);
    printf("%s\n%s\n", ciphertext, decrypted);
    return 0;
}
