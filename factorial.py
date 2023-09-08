import sys

def factorial(num):
    if num == 1 or 0:
        return 1
    else:
        return num * factorial(num - 1)


num = int(sys.argv[1])
facto = factorial(num)

print(f"Factorial of {num} is: {facto}")
