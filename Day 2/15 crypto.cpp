#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26
#define MAX_TEXT_SIZE 1000

const double letter_frequencies[ALPHABET_SIZE] = {
    8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015, 6.094, 6.966, 0.153, 0.772, 4.025,
    2.406, 6.749, 7.507, 1.929, 0.095, 5.987, 6.327, 9.056, 2.758, 0.978, 2.361, 0.150,
    1.974, 0.074
};

double calculate_score(const char *text) {
    int counts[ALPHABET_SIZE] = {0};
    int total_letters = 0;
    double score = 0.0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            counts[text[i] - 'a']++;
            total_letters++;
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            counts[text[i] - 'A']++;
            total_letters++;
        }
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        double observed = (double)counts[i] / total_letters * 100;
        score += (letter_frequencies[i] - observed) * (letter_frequencies[i] - observed);
    }

    return score;
}

void decrypt(const char *ciphertext, char *plaintext, int key) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            plaintext[i] = ((ciphertext[i] - 'a' - key + ALPHABET_SIZE) % ALPHABET_SIZE) + 'a';
        } else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            plaintext[i] = ((ciphertext[i] - 'A' - key + ALPHABET_SIZE) % ALPHABET_SIZE) + 'A';
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
}

void letter_frequency_attack(const char *ciphertext, int top_n) {
    char plaintext[MAX_TEXT_SIZE];
    double scores[ALPHABET_SIZE];

    for (int key = 0; key < ALPHABET_SIZE; key++) {
        decrypt(ciphertext, plaintext, key);
        scores[key] = calculate_score(plaintext);
    }

    for (int rank = 0; rank < top_n; rank++) {
        int best_key = -1;
        double best_score = 1e9;

        for (int key = 0; key < ALPHABET_SIZE; key++) {
            if (scores[key] < best_score) {
                best_score = scores[key];
                best_key = key;
            }
        }

        decrypt(ciphertext, plaintext, best_key);
        printf("Key: %d, Score: %.2f, Plaintext: %s\n", best_key, best_score, plaintext);
        scores[best_key] = 1e9;
    }
}

int main() {
    char ciphertext[MAX_TEXT_SIZE];
    int top_n;

    printf("Enter the ciphertext: ");
    fgets(ciphertext, MAX_TEXT_SIZE, stdin);
    ciphertext[strcspn(ciphertext, "\n")] = '\0';

    printf("Enter the number of top plaintexts to display: ");
    scanf("%d", &top_n);

    letter_frequency_attack(ciphertext, top_n);

    return 0;
}
