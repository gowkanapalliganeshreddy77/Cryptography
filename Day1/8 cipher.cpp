#include <stdio.h>
#include <string.h>
#define ALPHABET_SIZE 26
void create_cipher_alphabet(char *keyword, char *cipher_alphabet) {
    int used[ALPHABET_SIZE] = {0};
    int k = 0;
    for (int i = 0; i < strlen(keyword); i++) {
        char ch = keyword[i];
        if (ch >= 'A' && ch <= 'Z' && !used[ch - 'A']) {
            cipher_alphabet[k++] = ch;
            used[ch - 'A'] = 1;
        } else if (ch >= 'a' && ch <= 'z' && !used[ch - 'a']) {
            cipher_alphabet[k++] = ch - 'a' + 'A';
            used[ch - 'a'] = 1;
        }
    }
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A']) {
            cipher_alphabet[k++] = ch;
        }
    }
}
void encrypt(char *plaintext, char *cipher_alphabet, char *ciphertext) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = cipher_alphabet[plaintext[i] - 'a'] + 32;
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = cipher_alphabet[plaintext[i] - 'A'];
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[strlen(plaintext)] = '\0';
}
void decrypt(char *ciphertext, char *cipher_alphabet, char *plaintext) {
    char reverse_cipher[ALPHABET_SIZE];
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        reverse_cipher[i] = 'A' + i;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            if (cipher_alphabet[j] == reverse_cipher[i]) {
                reverse_cipher[j] = 'A' + i;
            }
        }
    }
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            plaintext[i] = reverse_cipher[ciphertext[i] - 'a'] + 32;
        } else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            plaintext[i] = reverse_cipher[ciphertext[i] - 'A'];
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
}
int main() {
    char keyword[] = "CIPHER";
    char cipher_alphabet[ALPHABET_SIZE];
    char plaintext[100], ciphertext[100], decrypted_text[100];
    create_cipher_alphabet(keyword, cipher_alphabet);
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;
    encrypt(plaintext, cipher_alphabet, ciphertext);
    printf("Encrypted ciphertext: %s\n", ciphertext);
    return 0;
}
