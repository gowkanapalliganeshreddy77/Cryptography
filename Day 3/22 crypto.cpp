#include <stdio.h>
#include <string.h>
void sdes_cbc_encrypt(char *plaintext, char *key, char *iv, char *ciphertext) {
    for (int i = 0; plaintext[i]; i++)
        ciphertext[i] = plaintext[i] ^ key[i % 10] ^ iv[i % 8];
}
void sdes_cbc_decrypt(char *ciphertext, char *key, char *iv, char *plaintext) {
    for (int i = 0; ciphertext[i]; i++)
        plaintext[i] = ciphertext[i] ^ key[i % 10] ^ iv[i % 8];
}
int main() {
    char plaintext[100] = "0000000100100011", key[11] = "0111111101", iv[9] = "10101010", ciphertext[100], decrypted[100];
    sdes_cbc_encrypt(plaintext, key, iv, ciphertext);
    sdes_cbc_decrypt(ciphertext, key, iv, decrypted);
    printf("%s\n%s\n", ciphertext, decrypted);
    return 0;
}
