#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
char matrix[SIZE][SIZE], positions[26];
void constructMatrix(char keyword[]) {
    int used[26] = {0}, idx = 0;
    used['J' - 'A'] = 1;
    for (int i = 0; keyword[i] || idx < 25; i++) {
        char ch = (keyword[i] && isalpha(keyword[i])) ? toupper(keyword[i]) : 'A' + idx;
        if (ch == 'J') ch = 'I';
        if (!used[ch - 'A']) {
            matrix[idx / SIZE][idx % SIZE] = ch;
            positions[ch - 'A'] = idx++;
            used[ch - 'A'] = 1;
        }
    }
}
void preprocess(char text[]) {
    char result[100];
    int idx = 0;
    for (int i = 0; text[i]; i++) {
        char ch = toupper(text[i]);
        if (!isalpha(ch)) continue;
        if (ch == 'J') ch = 'I';
        if (idx > 0 && result[idx - 1] == ch) result[idx++] = 'X';
        result[idx++] = ch;
    }
    if (idx % 2) result[idx++] = 'X';
    result[idx] = '\0';
    strcpy(text, result);
}
void encrypt(char text[], char cipher[]) {
    for (int i = 0; text[i]; i += 2) {
        int r1 = positions[text[i] - 'A'] / SIZE, c1 = positions[text[i] - 'A'] % SIZE;
        int r2 = positions[text[i + 1] - 'A'] / SIZE, c2 = positions[text[i + 1] - 'A'] % SIZE;
        cipher[i] = (r1 == r2) ? matrix[r1][(c1 + 1) % SIZE] : (c1 == c2) ? matrix[(r1 + 1) % SIZE][c1] : matrix[r1][c2];
        cipher[i + 1] = (r1 == r2) ? matrix[r2][(c2 + 1) % SIZE] : (c1 == c2) ? matrix[(r2 + 1) % SIZE][c2] : matrix[r2][c1];
    }
}
int main() {
    char keyword[100], plaintext[100], ciphertext[100];
    printf("Enter keyword: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0';
    constructMatrix(keyword);
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';
    preprocess(plaintext);
    encrypt(plaintext, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}
