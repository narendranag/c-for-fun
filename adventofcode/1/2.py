import re

'''
So the first thing we need to do is read the file and store the numbers in an array.
We can do this by reading the file line by line and then iterating through each line.
For each line, we can iterate through each character and check if it is a number.
If it is, we can store it in a variable. If we find another number, we can store it in another variable.
If we only find one number, we can assume that the second number is the same as the first number.
We can then add the two numbers together and store the result in an array.
Finally, we can iterate through the array and add all the numbers together to get the final sum.

Part 2:
We need to read the characters to see if THEY are a number and check if either the first or second number is written as a word
'''

# An array to store all the numbers
numbers = []
sum = 0

# Open the file input.txt and read lines into an array
with open('input.txt', 'r') as file:
    lines = file.readlines()

# Remove any trailing newline characters from each line
lines = [line.strip() for line in lines]

# We need to convert words to numbers and store it in a new array
numericlines = []


# Define the dictionary mapping first letters to numbers
first_letter_to_number = {
    'z': 'zero',
    'o': 'one',
    't': ['two', 'three'],
    'f': ['four', 'five'],
    's': ['six', 'seven'],
    'e': 'eight',
    'n': 'nine'
}

# Dictionary to store the mapping of words to numbers
word_to_number_mapping = {
    'nine': 9,
    'eight': 8,
    'seven': 7,
    'six': 6,
    'five': 5,
    'four': 4,
    'three': 3,
    'two': 2,
    'one': 1,
    'zero': 0
}

# Function to replace words with numbers in a line
def replace_words_with_numbers(line):
    i = 0
    while i < len(line):
        char = line[i]
        if char in first_letter_to_number:
            possible_words = first_letter_to_number[char]
            if isinstance(possible_words, list):
                for word in possible_words:
                    if line[i:i+len(word)] == word:
                        line = line[:i] + str(word_to_number_mapping[word]) + line[i+len(word):]
                        i += len(str(word_to_number_mapping[word])) - 1
                        break
            else:
                word = possible_words
                if line[i:i+len(word)] == word:
                    line = line[:i] + str(word_to_number_mapping[word]) + line[i+len(word):]
                    i += len(str(word_to_number_mapping[word])) - 1
        i += 1
    return line

# Iterate through the lines and update them
for line in lines:
    numericlines.append(replace_words_with_numbers(line))

# Now find the first and second number to sum them up
for line in numericlines:
    
    first = -1
    second = -1

    for character in line:
        # If the char is a number, store it in the first or second var
        if character.isnumeric():
            if first < 0:
                first = int(character)
            else:
                second = int(character)

    if second < 0:
        second = first

    numbers.append((first * 10) + second)
    sum += (first * 10) + second

print(sum)