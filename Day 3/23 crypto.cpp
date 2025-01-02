#include <stdio.h>
#include <string.h>
void sdes_ctr_encrypt(char *plaintext, char *key, char *counter, char *ciphertext) {
    for (int i = 0; plaintext[i]; i++)
        ciphertext[i] = plaintext[i] ^ key[i % 10] ^ counter[i % 8];
}
void sdes_ctr_decrypt(char *ciphertext, char *key, char *counter, char *plaintext) {
    for (int i = 0; ciphertext[i]; i++)
        plaintext[i] = ciphertext[i] ^ key[i % 10] ^ counter[i % 8];
}
int main() {
    char plaintext[100] = "000000010000001000000100", key[11] = "0111111101", counter[9] = "00000000", ciphertext[100], decrypted[100];
    sdes_ctr_encrypt(plaintext, key, counter, ciphertext);
    sdes_ctr_decrypt(ciphertext, key, counter, decrypted);
    printf("%s\n%s\n", ciphertext, decrypted);
    return 0;
}
