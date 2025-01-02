#include <stdio.h>
#include <string.h>
#define SIZE 5
void create_matrix(char *key, char matrix[SIZE][SIZE]) {
    int used[26] = {0};
    int k = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        if (key[i] != 'J' && !used[key[i] - 'A']) {
            matrix[k / SIZE][k % SIZE] = key[i];
            used[key[i] - 'A'] = 1;
            k++;
        }
    }
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A'] && ch != 'J') {
            matrix[k / SIZE][k % SIZE] = ch;
            k++;
        }
    }
}
void decrypt_pair(char a, char b, char matrix[SIZE][SIZE], char *result) {
    int row1, col1, row2, col2;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == a) {
                row1 = i;
                col1 = j;
            }
            if (matrix[i][j] == b) {
                row2 = i;
                col2 = j;
            }
        }
    }
    if (row1 == row2) {
        result[0] = matrix[row1][(col1 - 1 + SIZE) % SIZE];
        result[1] = matrix[row2][(col2 - 1 + SIZE) % SIZE];
    } else if (col1 == col2) {
        result[0] = matrix[(row1 - 1 + SIZE) % SIZE][col1];
        result[1] = matrix[(row2 - 1 + SIZE) % SIZE][col2];
    } else {
        result[0] = matrix[row1][col2];
        result[1] = matrix[row2][col1];
    }
}
void decrypt_playfair(char *ciphertext, char *key, char *plaintext) {
    char matrix[SIZE][SIZE];
    create_matrix(key, matrix);
    int len = strlen(ciphertext);
    int k = 0;
    for (int i = 0; i < len; i += 2) {
        char a = ciphertext[i];
        char b = ciphertext[i + 1];
        char result[2];

        decrypt_pair(a, b, matrix, result);

        plaintext[k++] = result[0];
        plaintext[k++] = result[1];
    }
    plaintext[k] = '\0';
}
int main() {
    char ciphertext[] = "KXJEY UREBE ZWEHE WRYTU HEYFS KREHE GOYFI WTTTU OLKSY CAJPO BOTEI ZONTX BYBNT GONEY CUZWR GDSON SXBOU YWRHE BAAHY USEDQ";
    char key[] = "PATROLBOAT";
    char plaintext[100];
    decrypt_playfair(ciphertext, key, plaintext);
    printf("Decrypted message: %s\n", plaintext);
    return 0;
}
