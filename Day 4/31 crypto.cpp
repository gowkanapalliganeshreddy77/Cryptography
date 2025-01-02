#include <stdio.h>
#include <string.h>

void left_shift_and_xor(unsigned char *input, int block_size, unsigned char *output, unsigned char constant) {
    for (int i = 0; i < block_size - 1; i++)
        output[i] = (input[i] << 1) | (input[i + 1] >> 7);
    output[block_size - 1] = (input[block_size - 1] << 1) ^ (constant * ((input[0] & 0x80) != 0));
}

int main() {
    unsigned char input[16] = {0}, subkey1[16], subkey2[16], constant = 0x87;
    left_shift_and_xor(input, 16, subkey1, constant);
    left_shift_and_xor(subkey1, 16, subkey2, constant);
    for (int i = 0; i < 16; i++) printf("%02x ", subkey2[i]);
    return 0;
}
