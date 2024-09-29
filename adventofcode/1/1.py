# An array to store all the numbers
numbers = []
sum = 0

# Open the file input.txt and read lines into an array
with open('input.txt', 'r') as file:
    lines = file.readlines()

# Remove any trailing newline characters from each line
lines = [line.strip() for line in lines]


for line in lines:
    
    first = -1
    second = -1

    for character in line:
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