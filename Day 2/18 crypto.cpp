#include <stdio.h>
void generate_keys(char initial_key[56], char keys[16][48]) {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 24; j++)
            keys[i][j] = initial_key[j];
        for (int j = 24; j < 48; j++)
            keys[i][j] = initial_key[j + 28];
    }
}
int main() {
    char initial_key[56], keys[16][48];
    generate_keys(initial_key, keys);
    return 0;
}
