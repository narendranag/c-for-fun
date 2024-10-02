#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int letter_length_of_number(int actual_number) {

    int number = actual_number;
    
    char number_in_words[100] = "";
    int units, tens, hundreds, thousands = 0;

    // Get the digits of the number
    if(number > 99) {
        hundreds = number / 100;
        number = number % 100;
    }
    if(number > 9) {
        tens = number / 10;
        number = number % 10;
    }
    units = number;

    // Construct the number in words

    char *units_words[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char *tens_words[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    char *teens_words[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char *hundreds_words[] = {"", "onehundred", "twohundred", "threehundred", "fourhundred", "fivehundred", "sixhundred", "sevenhundred", "eighthundred", "ninehundred"};
    char *thousands_words[] = {"", "onethousand", "two thousand", "three thousand", "four thousand", "five thousand", "six thousand", "seven thousand", "eight thousand", "nine thousand"};

    // if it is a single digit number
    if (actual_number < 10) {
        strcat(number_in_words, units_words[units]);
    }

    // Let's get the first edge case out of the way, check if the number is between 10 and 19 name it and break
    else if (actual_number >= 10 && actual_number <= 19) {
        strcat(number_in_words, teens_words[units]);
    } 
    
    // Now for a two digit number greater than 19
    else if (actual_number >= 20 && actual_number <= 99) {
        strcat(number_in_words, tens_words[tens]);
        if (units > 0) {
            // strcat(number_in_words, " ");
            strcat(number_in_words, units_words[units]);
        }
    }

    // Now for a three digit number between 100 and 999
    else if (actual_number >= 100 && actual_number <= 999) {

        strcat(number_in_words, hundreds_words[hundreds]);

        // Check if is 200 / 300 / 400 etc

        if(tens == 0 && units == 0) {
            // strcat(number_in_words, "");
            
        } else if (tens == 0 && units > 0) {
                strcat(number_in_words, "and");
                strcat(number_in_words, units_words[units]);
        } else if(tens == 1 && units > 0) {
            strcat(number_in_words, "and");
            strcat(number_in_words, teens_words[units]);
        } else {
            strcat(number_in_words, "and");
            strcat(number_in_words, tens_words[tens]);
            if (units > 0) {
                // strcat(number_in_words, "");
                strcat(number_in_words, units_words[units]);
            }

        }
    }
    else if (actual_number == 1000) {
        strcat(number_in_words, thousands_words[1]);
    }
    // printf("%s\n", number_in_words);
    return strlen(number_in_words);
}

int main(int argc, char const *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    int upto = atoi(argv[1]);

    int sum = 0;
    for (int i = 1; i <= upto; i++) {
        sum += letter_length_of_number(i);
    }
    printf("%d\n", sum);
    return 0;
}