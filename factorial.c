#include <stdio.h>
#include <stdlib.h>

unsigned long long factorial(long);

int main(int argc, char *argv[])
{

    unsigned long long facto;
    long num = strtol(argv[1], NULL, 10);

    facto = factorial(num);

    printf("Factorial of %s is: %llu\n", argv[1], facto);

    return 0;
}

unsigned long long factorial(long num)
{
    if (num == 0 || num == 1)
        return 1;
    return (num * factorial(num - 1));
}