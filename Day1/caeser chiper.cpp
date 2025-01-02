#include <stdio.h>
#include <string.h>
#include <ctype.h>
void caesarCipher(char text[], int k) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (isupper(ch)) {
            text[i] = 'A' + (ch - 'A' + k) % 26;
        }
        else if (islower(ch)) {
            text[i] = 'a' + (ch - 'a' + k) % 26;
        }
    }
}
int main() {
    char text[1000];
    int k;
    printf("Enter the text to encrypt: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; 
    printf("Enter the key (1-25): ");
    scanf("%d", &k);
    if (k < 1 || k > 25) {
        printf("Invalid key. Please use a key in the range 1-25.\n");
        return 1;
    }
    caesarCipher(text, k);
    printf("Encrypted text: %s\n", text);
    return 0;
}

