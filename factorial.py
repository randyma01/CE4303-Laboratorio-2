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
elapsed_time = end - start


print(f"-------------------------------------")
print(f"Factorial of {num}: {facto}\n")
print(f"Elapsed time: {elapsed_time}")
print(f"-------------------------------------")
