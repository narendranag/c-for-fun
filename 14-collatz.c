/*
Collatz Conjecture

A sequence of numbers if defined as below

n -> n/2 if n is even
n -> 3n + 1 if n is odd

Which starting number under 1000000 produces the longest sequence?

*/

#include <stdio.h>

int main() {
    long long int i, j, n, max = 0, max_i = 0;
    for (i = 2; i < 1000000; i++) {
        n = i;
        j = 0;
        while (n != 1) {
            if (n % 2 == 0) {
                n = n / 2;
            } else {
                n = 3 * n + 1;
            }
            j++;
        }
        if (j > max) {
            max = j;
            max_i = i;
        }
    }
    printf("%lld\n", max_i);
    return 0;
}