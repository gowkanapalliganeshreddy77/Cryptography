#include <stdio.h>
#include <string.h>
void cbc_mac(char *message, char *key, char *output) {
    for (int i = 0; message[i]; i++)
        output[i] = message[i] ^ key[i % 8];
}
int main() {
    char message[100] = "BLOCK", key[9] = "MACKEY", output[100];
    cbc_mac(message, key, output);
    printf("%s\n", output);
    return 0;
}
