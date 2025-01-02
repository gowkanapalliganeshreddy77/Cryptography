#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void frequency_analysis(char *ciphertext, int topN) {
    int freq[26] = {0};
    char alphabet[] = "etaoinshrdlcumwfgypbvkjxqz";
    char result[1000];

    for (int i = 0; ciphertext[i]; i++)
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z')
            freq[ciphertext[i] - 'a']++;

    for (int n = 0; n < topN; n++) {
        for (int i = 0; i < 26; i++) {
            result[0] = '\0';
            for (int j = 0; ciphertext[j]; j++) {
                if (ciphertext[j] >= 'a' && ciphertext[j] <= 'z')
                    result[j] = alphabet[i];
                else
                    result[j] = ciphertext[j];
            }
            printf("Possible Plaintext %d: %s\n", n + 1, result);
        }
    }
}
int main() {
    char ciphertext[1000];
    int topN;
    scanf("%s %d", ciphertext, &topN);
    frequency_analysis(ciphertext, topN);
    return 0;
}
