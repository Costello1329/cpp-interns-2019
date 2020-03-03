arr = input().split(" ")
firstNumber = arr[0]
command = arr[1]
secondNumber = arr[2]
equalSign = arr[3]
result = arr[4]

testPassed = False

if command is "+":
    testPassed = int(firstNumber) + int(secondNumber) == int(result)

elif command is "x":
    testPassed = int(firstNumber) * int(secondNumber) == int(result)

else:
    testPassed = False

if not testPassed:
	print("Test failed: " + firstNumber + " " + command + " " + secondNumber + " = " + result)
else:
	print("Test passed")
