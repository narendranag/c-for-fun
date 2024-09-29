/*
A triangular number is a number obtained by the continued summation of natural numbers. The 7th triangular number is 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

Let us list the factors of the first seven triangle numbers:

 1: 1
 3: 1,3
 6: 1,2,3,6

10: 1,2,5,10

What is the value of the first triangle number to have over five hundred divisors?

*/

#include <stdio.h>

int main() {
    int i = 1;
    int j = 2;
    int count = 0;
    int triangle = 1;
    while (count < 500) {
        count = 0;
        i = 1;
        triangle += j;
        j++;

        // Check factors

        while (i * i < triangle) {
            if (triangle % i == 0) {
                count += 2;
            }
            i++;
        }

        // Edge Case: If the number is a perfect square
        if (i * i == triangle) {
            count++;
        }
    }
    printf("%d\n", triangle);
    return 0;
}