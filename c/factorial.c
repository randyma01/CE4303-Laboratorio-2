#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long factorial(long);

int main(int argc, char *argv[])
{

    unsigned long long facto;
    long num = strtol(argv[1], NULL, 10);
    clock_t time;

    time = clock();
    facto = factorial(num);
    time = clock() - time;

    double time_taken = ((double)time) / CLOCKS_PER_SEC;

    printf("\n");
    printf("-------------------------------------\n");
    printf("Factorial of %s is: %llu\n", argv[1], facto);
    printf("\n");
    printf("Elapse time: %f\n", time_taken);
    printf("-------------------------------------");
    printf("\n");

    return 0;
}

unsigned long long factorial(long num)
{
    if (num == 0 || num == 1)
    {
        return 1;
    }
    else
    {
        return num * factorial(num - 1);
    }
}