#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 26

int mod(int a, int b) {
    int result = a % b;
    return result < 0 ? result + b : result;
}

void encrypt(char *message, int key[2][2]) {
    int len = strlen(message);
    for (int i = 0; i < len; i += 2) {
        int x = message[i] - 'a';
        int y = message[i + 1] - 'a';
        int enc_x = mod((key[0][0] * x + key[0][1] * y), MOD);
        int enc_y = mod((key[1][0] * x + key[1][1] * y), MOD);
        message[i] = enc_x + 'a';
        message[i + 1] = enc_y + 'a';
    }
}

void decrypt(char *ciphertext, int inv_key[2][2], int original_length) {
    int len = strlen(ciphertext);
    for (int i = 0; i < len; i += 2) {
        int x = ciphertext[i] - 'a';
        int y = ciphertext[i + 1] - 'a';
        int dec_x = mod((inv_key[0][0] * x + inv_key[0][1] * y), MOD);
        int dec_y = mod((inv_key[1][0] * x + inv_key[1][1] * y), MOD);
        ciphertext[i] = dec_x + 'a';
        ciphertext[i + 1] = dec_y + 'a';
    }
    ciphertext[original_length] = '\0'; 
}

int main() {
    char message[100];
    int key[2][2], inv_key[2][2];

    printf("Enter the message (lowercase letters only): ");
    scanf("%s", message);

    printf("Enter the encryption key (2x2 matrix, row-wise):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &key[i][j]);
        }
    }

    printf("Enter the decryption key (2x2 matrix, row-wise):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &inv_key[i][j]);
        }
    }

    int original_length = strlen(message);

    if (original_length % 2 != 0) {
        strcat(message, "x");
    }

    printf("Original message: %s\n", message);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, inv_key, original_length);
    printf("Decrypted message: %s\n", message);

    return 0;
}
