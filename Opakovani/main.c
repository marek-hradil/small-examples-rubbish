#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int length;
    float *value;
} NumbersArray;

void load_numbers_from_file(NumbersArray *numbers, FILE *file)
{
    int i = 0;
    int allocated = 10;
    float n = 0;
    float *value = malloc(allocated * sizeof(float));

    if (value == NULL)
    {
        printf("Couldn't allocate 'value' array.\n");
        exit(EXIT_FAILURE);
    }

    for (float n; fscanf(file, "%f", &n) != EOF; i++)
    {
        if (i == allocated)
        {
            allocated += 10;
            value = realloc(value, allocated * sizeof(float));
        }

        value[i] = n;
    }

    numbers->length = i;
    numbers->value = value;
}

void write_numbers_to_file(NumbersArray *numbers, FILE *file)
{
    for (int i = 0; i < numbers->length; i++)
    {
        fprintf(file, "%f\n", numbers->value[i]);
    }
}

int sort_numbers_fn(const void *a, const void *b)
{
    if (*(float *)a > *(float *)b)
    {
        return 1;
    }
    else if (*(float *)a < *(float *)b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void sort_numbers(NumbersArray *numbers)
{
    qsort(numbers->value, numbers->length, sizeof(float), sort_numbers_fn);
}

float min_from_numbers(NumbersArray *numbers)
{
    float min = numbers->value[0];
    for (int i = 0; i < numbers->length; i++)
    {
        if (numbers->value[i] < min)
        {
            min = numbers->value[i];
        }
    }

    return min;
}

float avg_of_numbers(NumbersArray *numbers)
{
    float sum = 0;
    int i = 0;
    for (; i < numbers->length; i++)
    {
        sum += numbers->value[i];
    }

    return sum / i;
}

void destroy_numbers(NumbersArray *numbers)
{
    free(numbers->value);
}

int main()
{
    FILE *input = fopen("./assets/input.txt", "r");
    if (input == NULL)
    {
        printf("Couldn't open input file.\n");
        exit(EXIT_FAILURE);
    }

    FILE *output = fopen("./assets/output.txt", "w");
    if (output == NULL)
    {
        printf("Couldn't open output file. \n");
        exit(EXIT_FAILURE);
    }

    NumbersArray numbers;

    load_numbers_from_file(&numbers, input);
    sort_numbers(&numbers);
    write_numbers_to_file(&numbers, output);
    destroy_numbers(&numbers);

    return EXIT_SUCCESS;
}