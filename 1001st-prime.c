/*
Find the 1001st prime number.
*/

#include <stdio.h>

int is_prime(int n) {
    if (n < 2) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    if (n % 2 == 0) {
        return 0;
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int count = 0;
    int i = 0;
    while (count < 10001) {
        if (is_prime(i)) {
            count++;
        }
        i++;
    }
    printf("%d\n", i - 1);
    return 0;
}