/*
Starting in the top left corner of a  grid, and only being able to move to the right and down, there are exactly 6  routes to the bottom right corner.
*/

#include <stdio.h>

int main() {
    int n = 20;
    long long int grid[n+1][n+1];
    for (int i = 0; i <= n; i++) {
        grid[i][n] = 1;
        grid[n][i] = 1;
    }
    for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= 0; j--) {
            grid[i][j] = grid[i+1][j] + grid[i][j+1];
        }
    }
    printf("%lld\n", grid[0][0]);
    return 0;
}