#include <stdio.h>
#include <string.h>

#define MAX_CIPHERTEXT_LENGTH 1000
#define ALPHABET_SIZE 26

void count_frequencies(const char *ciphertext, int *freq) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= '0' && ciphertext[i] <= '9') {
            freq[ciphertext[i] - '0']++;
        }
        else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            freq[ciphertext[i] - 'A' + 10]++;
        }
    }
}

void print_frequencies(int *freq) {
    for (int i = 0; i < ALPHABET_SIZE + 10; i++) {
        if (freq[i] > 0) {
            printf("%c : %d\n", (i < 10) ? ('0' + i) : ('A' + i - 10), freq[i]);
        }
    }
}

void decrypt_substitution(const char *ciphertext, char *decrypted, char *key) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= '0' && ciphertext[i] <= '9') {
            decrypted[i] = key[ciphertext[i] - '0'];
        }
        else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            decrypted[i] = key[ciphertext[i] - 'A' + 10];
        }
        else {
            decrypted[i] = ciphertext[i];
        }
    }
    decrypted[strlen(ciphertext)] = '\0';
}

int main() {
    char ciphertext[MAX_CIPHERTEXT_LENGTH];
    char decrypted[MAX_CIPHERTEXT_LENGTH];
    int freq[ALPHABET_SIZE + 10] = {0}; 
    char key[ALPHABET_SIZE + 10]; 

    printf("Enter the ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);
    ciphertext[strcspn(ciphertext, "\n")] = 0;

    count_frequencies(ciphertext, freq);
    printf("\nCharacter frequencies in the ciphertext:\n");
    print_frequencies(freq);

    printf("\nEnter the substitution key (e.g., 0->E, 1->T, etc.):\n");
    printf("For example, enter a mapping like: 0->E 1->T ...\n");

    for (int i = 0; i < ALPHABET_SIZE + 10; i++) {
        if (i < 10) {
            printf("Enter substitution for character '%c' (0-9): ", '0' + i);
        } else {
            printf("Enter substitution for character '%c' (A-Z): ", 'A' + i - 10);
        }
        scanf(" %c", &key[i]);  
    }

    decrypt_substitution(ciphertext, decrypted, key);
    printf("\nDecrypted message: %s\n", decrypted);

    return 0;
}