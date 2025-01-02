#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 26

int mod(int a, int b) {
    int result = a % b;
    return result < 0 ? result + b : result;
}

void matrix_multiply(int result[2][2], int mat1[2][2], int mat2[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
            result[i][j] = mod(result[i][j], MOD);
        }
    }
}

void known_plaintext_attack(int plaintext[2][2], int ciphertext[2][2], int key[2][2]) {
    int inv_plaintext[2][2];
    int det = mod(plaintext[0][0] * plaintext[1][1] - plaintext[0][1] * plaintext[1][0], MOD);
    int det_inv = -1;

    for (int i = 0; i < MOD; i++) {
        if (mod(det * i, MOD) == 1) {
            det_inv = i;
            break;
        }
    }

    if (det_inv == -1) {
        printf("Inverse does not exist for the plaintext matrix.\n");
        return;
    }

    inv_plaintext[0][0] = mod(plaintext[1][1] * det_inv, MOD);
    inv_plaintext[1][1] = mod(plaintext[0][0] * det_inv, MOD);
    inv_plaintext[0][1] = mod(-plaintext[0][1] * det_inv, MOD);
    inv_plaintext[1][0] = mod(-plaintext[1][0] * det_inv, MOD);

    matrix_multiply(key, inv_plaintext, ciphertext);
}

int main() {
    int plaintext[2][2], ciphertext[2][2], key[2][2];

    printf("Enter the plaintext matrix (2x2, row-wise):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &plaintext[i][j]);
        }
    }

    printf("Enter the ciphertext matrix (2x2, row-wise):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &ciphertext[i][j]);
        }
    }

    known_plaintext_attack(plaintext, ciphertext, key);

    printf("Recovered key matrix:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", key[i][j]);
        }
        printf("\n");
    }

    return 0;
}
