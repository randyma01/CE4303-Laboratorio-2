#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int countOccurrences(FILE *file, const char *word);

int main()
{
    const char *target_word = "ipsum";
    const char *file_name = "text.txt";
    clock_t time;

    FILE *file = fopen(file_name, "r");
    if (file == NULL)
    {
        perror("Could not open the file");
        return 1;
    }

    time = clock();
    int occurrences = countOccurrences(file, target_word);
    time = clock() - time;

    fclose(file);

    double time_taken = ((double)time) / CLOCKS_PER_SEC;

    printf("\n");
    printf("-------------------------------------\n");
    printf("The word '%s' appears %d times in the file.\n", target_word, occurrences);
    printf("\n");
    printf("Elapse time: %f\n", time_taken);
    printf("-------------------------------------");
    printf("\n");

    return 0;
}

int countOccurrences(FILE *file, const char *word)
{
    char fileWord[100];
    int count = 0;

    while (fscanf(file, "%s", fileWord) != EOF)
    {
        if (strcmp(word, fileWord) == 0)
        {
            count++;
        }
    }

    return count;
}