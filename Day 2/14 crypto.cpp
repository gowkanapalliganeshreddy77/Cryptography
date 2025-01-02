#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 26

void encrypt(char *plaintext, int *keystream, char *ciphertext) {
    int len = strlen(plaintext);
    for (int i = 0; i < len; i++) {
        if (plaintext[i] == ' ') {
            ciphertext[i] = ' '; 
        } else {
            int shift = keystream[i % MOD];
            ciphertext[i] = ((plaintext[i] - 'a' + shift) % MOD) + 'a';
        }
    }
    ciphertext[len] = '\0';
}

void decrypt(char *ciphertext, int *keystream, char *plaintext) {
    int len = strlen(ciphertext);
    for (int i = 0; i < len; i++) {
        if (ciphertext[i] == ' ') {
            plaintext[i] = ' '; 
        } else {
            int shift = keystream[i % MOD];
            plaintext[i] = ((ciphertext[i] - 'a' - shift + MOD) % MOD) + 'a';
        }
    }
    plaintext[len] = '\0';
}

int main() {
    char plaintext[] = "send more money";
    int keystream[] = {9, 0, 17, 23, 15, 21, 14, 11, 11, 2, 8, 9};
    char ciphertext[100];
    char decrypted[100];

    encrypt(plaintext, keystream, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, keystream, decrypted);
    printf("Decrypted text: %s\n", decrypted);

    char new_plaintext[] = "cash not needed";
    char new_ciphertext[100];

    encrypt(new_plaintext, keystream, new_ciphertext);
    printf("New ciphertext: %s\n", new_ciphertext);

    return 0;
}
