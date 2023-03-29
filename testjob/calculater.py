#!/usr/bin/python3

print("This is made by DYX, it's a calculater!")
print("Just type 1 to use or type 2 to exit")

a = input("Please input:")

if a == '1':
    print("Let's start!")
    print("Type to choose the mode")
    print("a for plus, b for minus, c for multiply and d for divide")
    b = input("Please input:")

    match b:
        case 'a':
            print("Type two numbers to compute them")
            c, d = input("Please type the first number:"),input("Please type the second number:")
            print("The result is ", int(c) + int(d))

