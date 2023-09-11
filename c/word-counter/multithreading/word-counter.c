#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 5

void *countOccurrences(void *arg);

struct ThreadData
{
    FILE *file;
    const char *target_word;
    int start_index;
    int end_index;
    int thread_id;
};

int total_occurrences = 0;
pthread_mutex_t mutex;

int main()
{
    const char *target_word = "ipsum";
    const char *file_name = "text.txt";
    clock_t time;

    FILE *file = fopen(file_name, "r");
    if (file == NULL)
    {
        perror("Could not open the file.");
        return 1;
    }

    int num_threads;
    printf("Enter the amount of threads (1-%d): ", MAX_THREADS);
    scanf("%d", &num_threads);

    if (num_threads < 1 || num_threads > MAX_THREADS)
    {
        printf("CThe amount of threads entered is not valid.\n");
        fclose(file);
        return 1;
    }

    pthread_t threads[MAX_THREADS];
    struct ThreadData thread_data[MAX_THREADS];
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    long section_size = file_size / num_threads;
    long remaining = file_size % num_threads;

    pthread_mutex_init(&mutex, NULL);

    time = clock();

    for (int i = 0; i < num_threads; i++)
    {
        thread_data[i].file = file;
        thread_data[i].target_word = target_word;
        thread_data[i].start_index = i * section_size;
        thread_data[i].end_index = (i + 1) * section_size - 1;
        thread_data[i].thread_id = i;

        if (i == num_threads - 1)
        {
            thread_data[i].end_index += remaining;
        }

        pthread_create(&threads[i], &attr, countOccurrences, &thread_data[i]);
    }

    for (int i = 0; i < num_threads; i++)
    {
        pthread_join(threads[i], NULL);
    }

    time = clock() - time;

    fclose(file);

    double time_taken = ((double)time) / CLOCKS_PER_SEC;

    pthread_mutex_destroy(&mutex);

    printf("\n");
    printf("-------------------------------------\n");
    printf("The word '%s' appears %d times in the file.\n", target_word, total_occurrences);
    printf("\n");
    printf("Elapse time: %f\n", time_taken);
    printf("-------------------------------------");
    printf("\n");

    return 0;
}

void *countOccurrences(void *arg)
{
    struct ThreadData *data = (struct ThreadData *)arg;
    int count = 0;

    fseek(data->file, data->start_index, SEEK_SET);
    char word[100];

    while (fscanf(data->file, "%s", word) != EOF && ftell(data->file) <= data->end_index)
    {
        if (strcmp(data->target_word, word) == 0)
        {
            count++;
        }
    }

    pthread_mutex_lock(&mutex);
    total_occurrences += count;
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}