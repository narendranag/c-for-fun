/*
Starting in the top left corner of a  grid, and only being able to move to the right and down, there are exactly 6  routes to the bottom right corner.

Comment:
This was a super interesting problem, and I went down a rabbit hole as I started to explroe what the mathematics is. Turns out there is a very simple binomial approach.

This thread: https://projecteuler.net/thread=15

My approach:


*/

#include <stdio.h>

int main() {

    /*
        The code begins by defining the size of the grid with int n = 20;, 
        which means the grid will be 21x21 (since it includes the 0th row and column). 
        
        It then declares a 2D array grid of size (n+1) x (n+1) to store the 
        number of paths to each point in the grid. The long long int type is used to 
        handle large numbers.
    */

    int n = 20;
    long long int grid[n+1][n+1];

    /*
        The first for loop initializes the boundary conditions of the grid -- setting 
        the rightmost column and the bottom row to 1. There is only one way to reach 
        any cell in the last row or column: by moving straight down or straight right, 
        respectively.
    */
    for (int i = 0; i <= n; i++) {
        grid[i][n] = 1;
        grid[n][i] = 1;
    }

    /*
        The second for loop iterates through the grid from the bottom right corner 
        to the top left corner, calculating the number of paths to each cell based 
        on the sum of the paths to the cell below it and the cell to its right.
    */
    for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= 0; j--) {
            grid[i][j] = grid[i+1][j] + grid[i][j+1];
        }
    }
    printf("%lld\n", grid[0][0]);
    return 0;
}