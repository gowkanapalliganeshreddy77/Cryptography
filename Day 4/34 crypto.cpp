#include <stdio.h>
#include <string.h>

void pad_message(char *message, int block_size) {
    int len = strlen(message), pad_len = block_size - (len % block_size);
    for (int i = 0; i < pad_len - 1; i++) message[len + i] = '0';
    message[len + pad_len - 1] = '1';
    message[len + pad_len] = '\0';
}

int main() {
    char message[100];
    int block_size;
    scanf("%s %d", message, &block_size);
    pad_message(message, block_size);
    printf("%s\n", message);
    return 0;
}
