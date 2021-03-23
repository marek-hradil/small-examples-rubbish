#include <stdlib.h>
#include <stdio.h>
#include "coeficients.h"

#define ITERATION_LIMIT 10000

int main(int argc, char *argv[])
{
    Coeficients *c = load_coeficients_from_file("./assets/rovnice.txt");

    if (quantify_coeficients(c, c->interval_start) * quantify_coeficients(c, c->interval_end) > 0)
    {
        printf("Cannot solve \n");
        return EXIT_FAILURE;
    }

    double result = 0;
    int iteration = 0;
    for (;;)
    {
        result = regula_falsi(c);
        double result_value = quantify_coeficients(c, result);

        if (result_value < c->error || iteration > ITERATION_LIMIT)
        {
            break;
        }

        if (result_value * quantify_coeficients(c, c->interval_start) < 0)
        {
            c->interval_end = result;
        }

        if (result_value * quantify_coeficients(c, c->interval_end) < 0)
        {
            c->interval_start = result;
        }

        iteration += 1;
    }

    printf("Result is: %lf\n", result);

    return EXIT_SUCCESS;
}