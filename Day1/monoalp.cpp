#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ALPHABET_SIZE 26
void monoalphabeticCipher(char plaintext[], char key[]) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];
        if (isupper(ch)) {
            plaintext[i] = key[ch - 'A'];
        }
        else if (islower(ch)) {
            plaintext[i] = tolower(key[ch - 'a']);
        }
    }
}
int isValidKey(char key[]) {
    int letterCount[ALPHABET_SIZE] = {0};
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (!isalpha(key[i])) {
            return 0; 
        }
        int index = toupper(key[i]) - 'A';
        letterCount[index]++;
        if (letterCount[index] > 1) {
            return 0;
        }
    }
    return 1;
}
int main() {
    char plaintext[1000];
    char key[ALPHABET_SIZE + 1]; 
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 
    printf("Enter the substitution key (26 unique letters): ");
    scanf("%26s", key);
    if (strlen(key) != ALPHABET_SIZE || !isValidKey(key)) {
        printf("Invalid key. The key must contain 26 unique alphabetic characters.\n");
        return 1;
    }
    monoalphabeticCipher(plaintext, key);
    printf("Encrypted text: %s\n", plaintext);
    return 0;
}

