#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

void print_help()
{
    printf("Usage: [-h] {+ | - | * | / } <lines> \n");
}

float add(float a, float b)
{
    return a + b;
}

float subtract(float a, float b)
{
    return a - b;
}

float multiply(float a, float b)
{
    return a * b;
}

float divide(float a, float b)
{
    assert(b != 0);

    return a / b;
}

void process_lines(float (*opertation_fn)(float, float))
{
    char *line;
    size_t line_len;

    while (getline(&line, &line_len, stdin) != -1)
    {
        float accumulator = 0;
        int i = 0;
        char *token, *rest = line;

        while ((token = strtok_r(rest, " ", &rest)))
        {
            float number = strtof(token, NULL);
            if (i == 0)
            {
                accumulator = number;
            }
            else
            {
                accumulator = opertation_fn(accumulator, number);
            }

            i++;
        }

        printf("%f \n", accumulator);
    }
}

int main(int argc, char *argv[])
{
    if (strcmp(argv[1], "-h") == 0)
    {
        print_help();
        return EXIT_SUCCESS;
    }

    int operator= argv[1][0];
    switch (operator)
    {
    case '+':
        process_lines(add);
        break;
    case '-':
        process_lines(subtract);
        break;
    case '*':
        process_lines(multiply);
        break;
    case '/':
        process_lines(divide);
        break;
    default:
        print_help();
    }

    return EXIT_SUCCESS;
}