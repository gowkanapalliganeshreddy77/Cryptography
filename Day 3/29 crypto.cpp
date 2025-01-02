#include <stdio.h>
int count_nonzero_lanes(int lanes[5][5]) {
    int count = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (lanes[i][j] != 0) count++;
    return count;
}
int main() {
    int lanes[5][5] = {{0}}, rounds = 0;
    lanes[0][0] = 1;
    while (count_nonzero_lanes(lanes) < 25) {
        rounds++;
        lanes[rounds % 5][rounds % 5] = 1;
    }
    printf("%d\n", rounds);
    return 0;
}
