#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }
    
    char *number = argv[1];
    char number_in_words[100] = "";
    int actual_number, units, tens, hundreds, thousands = 0;


    int number_length = strlen(number);
    actual_number = atoi(number);

    printf("Number: %d\n", actual_number);

    if(actual_number >= 1000) {
        printf("Number is too large\n");
        return 1;
    }

    printf("Number length: %d\n", number_length);

    printf("-------------------\n");

    if (number_length >= 1) units = number[number_length - 1] - '0';
    if (number_length >= 2) tens = number[number_length - 2] - '0';
    if (number_length >= 3) hundreds = number[number_length - 3] - '0';
    if (number_length >= 4) thousands = number[number_length - 4] - '0';


    // Construct the number in words

    char *units_words[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char *tens_words[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    char *teens_words[] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char *hundreds_words[] = {"", "one hundred", "two hundred", "three hundred", "four hundred", "five hundred", "six hundred", "seven hundred", "eight hundred", "nine hundred"};
    char *thousands_words[] = {"", "one thousand", "two thousand", "three thousand", "four thousand", "five thousand", "six thousand", "seven thousand", "eight thousand", "nine thousand"};

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
            strcat(number_in_words, " ");
            strcat(number_in_words, units_words[units]);
        }
    }

    // Now for a three digit number between 100 and 999
    else if (actual_number >= 100 && actual_number < 1000) {

        strcat(number_in_words, hundreds_words[hundreds]);

        if (tens == 0) {
            if (units > 0) {
                strcat(number_in_words, " and ");
                strcat(number_in_words, units_words[units]);
            }
        } else if (tens == 1) {
            strcat(number_in_words, " and ");
            strcat(number_in_words, teens_words[units]);
        } else {
            strcat(number_in_words, " and ");
            strcat(number_in_words, tens_words[tens]);
            if (units > 0) {
                strcat(number_in_words, " ");
                strcat(number_in_words, units_words[units]);
            }

        }
    }

    printf("Number in words: %s\n", number_in_words);
    return 0;
}