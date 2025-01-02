#include <stdio.h>
#include <string.h>
void generate_decryption_keys(char keys[16][7], char decryption_keys[16][7]) {
    for (int i = 0; i < 16; i++) {
        strcpy(decryption_keys[i], keys[15 - i]);
    }
}
int main() {
    char keys[16][7] = {"K1", "K2", "K3", "K4", "K5", "K6", "K7", "K8", "K9", "K10", "K11", "K12", "K13", "K14", "K15", "K16"};
    char decryption_keys[16][7];
    generate_decryption_keys(keys, decryption_keys);
    for (int i = 0; i < 16; i++) {
        printf("%s\n", decryption_keys[i]);
    }
    return 0;
}
