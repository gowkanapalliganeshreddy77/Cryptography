#include <stdio.h>
void reverse_keys(char keys[16][48], char reversed[16][48]) {
    for (int i = 0; i < 16; i++)
        for (int j = 0; j < 48; j++)
            reversed[15 - i][j] = keys[i][j];
}
int main() {
    char keys[16][48], reversed[16][48];
    reverse_keys(keys, reversed);
    return 0;
}
