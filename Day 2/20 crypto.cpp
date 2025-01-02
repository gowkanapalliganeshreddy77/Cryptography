#include <stdio.h>
void error_propagation_cbc(char ciphertext[], int block_size) {
    for (int i = 0; ciphertext[i]; i += block_size)
        ciphertext[i] ^= 1;
}
int main() {
    char ciphertext[100];
    int block_size;
    error_propagation_cbc(ciphertext, block_size);
    return 0;
}
