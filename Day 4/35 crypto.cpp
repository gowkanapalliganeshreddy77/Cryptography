#include <stdio.h>
#include <string.h>

void vigenere_encrypt(char *plaintext, int *key, char *ciphertext) {
    for (int i = 0; plaintext[i]; i++)
        ciphertext[i] = ((plaintext[i] - 'A') + key[i]) % 26 + 'A';
}

void vigenere_decrypt(char *ciphertext, int *key, char *plaintext) {
    for (int i = 0; ciphertext[i]; i++)
        plaintext[i] = ((ciphertext[i] - 'A') - key[i] + 26) % 26 + 'A';
}

int main() {
    char plaintext[100] = "HELLO", ciphertext[100], decrypted[100];
    int key[100] = {3, 19, 5, 10, 15};
    vigenere_encrypt(plaintext, key, ciphertext);
    vigenere_decrypt(ciphertext, key, decrypted);
    printf("%s\n%s\n", ciphertext, decrypted);
    return 0;
}
