#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int letter_length_of_number(int original_number) {

    // Key Variables
    char number_in_words[100] = "";
    int character_count = 0;

    // Utility Variables
    int number = original_number;
    int units_digit = 0;
    int tens_digit = 0;
    int hundreds_digit = 0;
    int thousands_digit = 0;
    char *units_words[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char *tens_words[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    char *teens_words[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    // Break the number down into it's constituent digits
    if(number > 999) {
        thousands_digit = number / 1000;
        number = number % 1000;
    }
    if(number > 99) {
        hundreds_digit = number / 100;
        number = number % 100;
    }
    if(number > 9) {
        tens_digit = number / 10;
        number = number % 10;
    }

    units_digit = number;

    // Construct the number in words


    // if it is a single digit number
    if (original_number < 10) {
        strcat(number_in_words, units_words[units_digit]);
    }

    // Let's get the first edge case out of the way, check if the number is between 10 and 19 name it and break
    if (original_number >= 10 && original_number <= 19) {
        strcat(number_in_words, teens_words[units_digit]);
    } 
    
    // Now for a two digit number greater than 19
    if (original_number >= 20 && original_number <= 99) {
        strcat(number_in_words, tens_words[tens_digit]);
        if (units_digit > 0) {
            strcat(number_in_words, " ");
            strcat(number_in_words, units_words[units_digit]);
        }
    }

    // Now for a three digit number between 100 and 999
    if (original_number >= 100 && original_number <= 999) {

        strcat(number_in_words, units_words[hundreds_digit]);
        strcat(number_in_words, " hundred");

        // If the number is in the for X0X

        if (tens_digit == 0 && units_digit > 0) {
                strcat(number_in_words, " and ");
                strcat(number_in_words, units_words[units_digit]);
        }
        // if the number is in the form x1x
        if (tens_digit == 1) {
            strcat(number_in_words, " and ");
            strcat(number_in_words, teens_words[units_digit]);
        } 

        // the number is in the form x(>2)x
        if (tens_digit > 1) {
            strcat(number_in_words, " and ");
            strcat(number_in_words, tens_words[tens_digit]);

            if (units_digit > 0) {
                strcat(number_in_words, " ");
                strcat(number_in_words, units_words[units_digit]);
            }
        }
    }
    if (original_number == 1000) {
        strcat(number_in_words, "one thousand");
    }
    printf("%d, %s, ", original_number, number_in_words);

    for(int i = 0; i < strlen(number_in_words); i++) {
        if(number_in_words[i] != ' ') {
            character_count++;
            // printf("Character #%d is %c\n", character_count, number_in_words[i]);

        }
    }
    printf("%d\n", character_count);
    return character_count;
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