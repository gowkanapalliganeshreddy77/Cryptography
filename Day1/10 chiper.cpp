#include <stdio.h>
#include <string.h>
#define SIZE 5
void create_matrix(char *key, char matrix[SIZE][SIZE]) {
    int used[26] = {0};
    int k = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        if (!used[key[i] - 'A']) {
            matrix[k / SIZE][k % SIZE] = key[i];
            used[key[i] - 'A'] = 1;
            k++;
        }
    }
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A']) {
            matrix[k / SIZE][k % SIZE] = ch;
            k++;
        }
    }
}
void encrypt_pair(char a, char b, char matrix[SIZE][SIZE], char *result) {
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
        result[0] = matrix[row1][(col1 + 1) % SIZE];
        result[1] = matrix[row2][(col2 + 1) % SIZE];
    } else if (col1 == col2) {
        result[0] = matrix[(row1 + 1) % SIZE][col1];
        result[1] = matrix[(row2 + 1) % SIZE][col2];
    } else {
        result[0] = matrix[row1][col2];
        result[1] = matrix[row2][col1];
    }
}
void preprocess_message(char *message, char *processed_message) {
    int k = 0;
    for (int i = 0; message[i] != '\0'; i++) {
        if (message[i] != ' ') {
            processed_message[k++] = (message[i] >= 'a' && message[i] <= 'z') ? message[i] - 32 : message[i];
        }
    }
    if (k % 2 != 0) {
        processed_message[k++] = 'X';
    }
    processed_message[k] = '\0';
}
void encrypt_playfair(char *message, char *key, char *ciphertext) {
    char matrix[SIZE][SIZE];
    char processed_message[100];
    preprocess_message(message, processed_message);
    create_matrix(key, matrix);
    int k = 0;
    for (int i = 0; processed_message[i] != '\0'; i += 2) {
        char a = processed_message[i];
        char b = processed_message[i + 1];
        char result[2];
        encrypt_pair(a, b, matrix, result);
        ciphertext[k++] = result[0];
        ciphertext[k++] = result[1];
    }
    ciphertext[k] = '\0';
}
int main() {
    char key[] = "MFHIJK UNOPQ ZVWXY ELARG DSTBC";
    char message[] = "Must see you over Cadogan West. Coming at once.";
    char ciphertext[100];
    encrypt_playfair(message, key, ciphertext);
    printf("Encrypted message: %s\n", ciphertext); 
    return 0;
}
