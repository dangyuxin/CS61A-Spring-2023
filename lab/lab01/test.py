#!/usr/bin/python3
 
def square_twice(f,x):
    return f(f(x))

def square(x):
    return x**2

print(square_twice(square,2))