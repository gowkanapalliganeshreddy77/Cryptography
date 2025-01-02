#include <stdio.h>
#include <string.h>
#include <ctype.h>
void encrypt(char plaintext[], char key[], char ciphertext[]) {
    int keyLen = strlen(key);
    for (int i = 0, j = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            ciphertext[i] = (ch - base + (toupper(key[j % keyLen]) - 'A')) % 26 + base;
            j++;
        } else {
            ciphertext[i] = ch;
        }
    }
}
int main() {
    char plaintext[100], key[100], ciphertext[100] = {0};
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';
    printf("Enter the key: ");
    scanf("%s", key);
    encrypt(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}
