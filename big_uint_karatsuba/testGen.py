from random import randrange
command = input()

# Just generating BigUint number with 100-1000 digits count:
firstNum = randrange(10 ** randrange(100, 1000))
secondNum = randrange(10 ** randrange(100, 1000))

if command is "-":
    if firstNum < secondNum:
        temp = firstNum
        firstNum = secondNum
        secondNum = temp

print(firstNum)

# Printing command, that was received from the bash
print(command)

# Just generating BigUint number with 100-1000 digits count:
print(secondNum)
