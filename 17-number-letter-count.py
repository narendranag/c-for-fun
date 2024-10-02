'''
Euler Problem 17

Figure out how to convert a number into it's equivalent word and then count 
the number of letters used in the word while ignoring spaces

'''

def char_count_of_number_in_words(number):

    # All our variables

    original_number = number
    number_in_words = ""
    character_count = 0

    thousands_digit = 0
    hundreds_digit = 0
    tens_digit = 0
    units_digit = 0

    unit_words = ["","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
    teen_words = ["ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
    ten_words = ["", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]

    # Breaking down the number into it's digits

    if(number > 999):
        thousands_digit = int(number / 1000)
        number = number % 1000

    if(number > 99):
        hundreds_digit = int(number / 100)
        number = number % 100

    if(number > 9):
        tens_digit = int(number / 10)
        number = number % 10

    units_digit = number

    # Converting digits into words

    # If Single Digit
    if (original_number < 10):
        number_in_words = unit_words[units_digit]

    # If 10, 11 .. 19
    elif (original_number >= 10) and (original_number <=19):
        number_in_words = teen_words[units_digit]

    # If between 20 and 99
    elif (original_number >= 20) and (original_number < 100):
        number_in_words = ten_words[tens_digit]

        if(units_digit > 0):
            number_in_words += " " + unit_words[units_digit]

    # If between 100 and 999
    elif (original_number >= 100) and (original_number < 1000):
        
        number_in_words = unit_words[hundreds_digit] + " hundred"
        
        # Only proceed if the number is not an x00 (100, 200 etc)

        if(tens_digit == 0) and (units_digit > 0):
            number_in_words += " and " + unit_words[units_digit]
            

        elif(tens_digit == 1) and (units_digit > 0):
            number_in_words += " and " + teen_words[units_digit]

        elif(tens_digit > 1):
            number_in_words += " and " + ten_words[tens_digit]

            if(units_digit > 0):
                number_in_words += " " + unit_words[units_digit]

    # If between 1000 and 9999
    elif (original_number >= 1000) and (original_number < 10000):
        number_in_words = unit_words[thousands_digit] + " thousand"
        

        # If number is X0XX

        if(hundreds_digit == 0) and (tens_digit == 0) and (units_digit > 0):
            number_in_words += " and " + unit_words[units_digit]
            character_count += len(unit_words[units_digit]) + 3

        elif(hundreds_digit == 0) and (tens_digit == 1) and (units_digit > 0):
            number_in_words += " and " + teen_words[units_digit]
            

        elif(hundreds_digit == 0) and (tens_digit > 1) and (units_digit >= 0):
            number_in_words += " and " + ten_words[tens_digit]
            
            if(units_digit > 0):
                    number_in_words += " " + unit_words[units_digit]
                    
        # If number is XXXX
        elif(hundreds_digit > 0):
            number_in_words += " " + unit_words[hundreds_digit] + " hundred"
            

            if(tens_digit == 0) and (units_digit > 0):
                    number_in_words += " and " + unit_words[units_digit]
                    

            elif(tens_digit == 1) and (units_digit > 0):
                number_in_words += " and " + teen_words[units_digit]
                

            elif(tens_digit > 1):
                number_in_words += " and " + ten_words[tens_digit]
                

                if(units_digit > 0):
                    number_in_words += " " + unit_words[units_digit]


    # Find the number of characters in the word minus spaces
    for character in number_in_words:
        if character != " ":
            character_count += 1

    print(f"{original_number}, {number_in_words}, {character_count}")
    
    return character_count


# Let's loop this
sum = 0

for i in range(1,1001) :
    sum += char_count_of_number_in_words(i)

print(f"Total Character Count for all numbers between 1 and {i}: {sum}")