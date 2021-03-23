#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_help()
{
    printf("Usage: ./main.out [-h] {head | tail} <number>");
}

void run_head(int count)
{
    char *line;
    size_t line_len;

    for (int i = 0; i < count; i++)
    {
        if (getline(&line, &line_len, stdin) == -1)
        {
            break;
        }

        printf("%s", line);
    }
}

void run_tail(int count)
{
    char **buffer = calloc(count, sizeof(char *));
    int i = 0;
    char *line;
    char *line_buffer;
    size_t line_len;

    while (getline(&line, &line_len, stdin) != -1)
    {
        line_buffer = malloc(sizeof(char) * line_len);
        if (buffer[i % count] != 0)
        {
            free(buffer[i % count]);
        }

        strcpy(line_buffer, line);

        buffer[i % count] = line_buffer;

        i++;
    }

    int safe_count = count > i ? i : count;
    for (int j = 0; j < safe_count; j++)
    {
        printf("%s", buffer[(i + j) % safe_count]);
    }

    for (int j = 0; j < safe_count; j++)
    {
        free(buffer[j]);
    }

    free(buffer);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Atleast one parameter must be provided.\n");
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "-h") == 0)
    {
        print_help();
        return EXIT_SUCCESS;
    }

    if (argc < 3)
    {
        fprintf(stderr, "Count parameter must be provided.\n");
        return EXIT_FAILURE;
    }

    int count = strtol(argv[2], NULL, 10);
    if (strcmp(argv[1], "head") == 0)
    {
        run_head(count);
        return EXIT_SUCCESS;
    }

    if (strcmp(argv[1], "tail") == 0)
    {
        run_tail(count);
        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}