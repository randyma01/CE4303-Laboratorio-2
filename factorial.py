import sys
from timeit import default_timer as timer


def factorial(num):
    if num == 1 or 0:
        return 1
    else:
        return num * factorial(num - 1)


num = int(sys.argv[1])
start = timer()
facto = factorial(num)
end = timer()
elapse_time = end - start

print('\n')
print(f"-------------------------------------")
print(f"Factorial of {num}: {facto}\n")
print(f"Elapse time: {elapse_time}")
print(f"-------------------------------------")
print('\n')
