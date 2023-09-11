#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long factorial(long);
void delay(int);

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

void delay(int milli_seconds)
{
    long pause;
    clock_t now, then;

    pause = milli_seconds * (CLOCKS_PER_SEC / 1000);
    now = then = clock();
    while ((now - then) < pause)
        now = clock();
}

unsigned long long factorial(long num)
{
    if (num == 0 || num == 1)
    {
        printf("Recursion: end by condition\n");
        return 1;
    }
    else
    {
        delay(5000);
        printf("Recursion: #%ld\n", num);
        return num * factorial(num - 1);
    }
}