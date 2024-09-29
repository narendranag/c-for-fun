/*
Euler Problem #16: Power Digit Sum
Calculate the sum of the digits of 2^1000.
*/

#include <stdio.h>

int main() {
    int n = 1000;

    // initialize array to store digits of 2^n and set the starting value to 0
    int digits[1000] = {0};
    
    digits[0] = 1;

    for (int i = 0; i < n; i++) {
        int carry = 0;
        for (int j = 0; j < 1000; j++) {
            int product = 2 * digits[j] + carry;
            digits[j] = product % 10;
            carry = product / 10;
        }
    }

    int sum = 0;
    for (int i = 0; i < 1000; i++) {
        sum += digits[i];
    }

    printf("%d\n", sum);
    return 0;
}