#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int countOccurrences(FILE *file, const char *word);

int main()
{
    const char *target_word = "your_word_to_count";
    const char *file_name = "text.txt";

    FILE *file = fopen(file_name, "r");
    if (file == NULL)
    {
        perror("Could not open the file");
        return 1;
    }

    clock_t start = clock();
    int occurrences = countOccurrences(file, target_word);
    clock_t end = clock();

    fclose(file);

    double execution_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("The word '%s' appears %d times in the file.\n", target_word, occurrences);
    printf("Execution time: %.4f seconds\n", execution_time);

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