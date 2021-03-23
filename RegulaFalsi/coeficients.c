#include <stdlib.h>
#include <stdio.h>
#include "coeficients.h"

Coeficients *build_coeficients(int length)
{
    Coeficients *c = malloc(sizeof(Coeficients));
    if (c == NULL)
    {
        exit(EXIT_FAILURE);
    }

    c->length = length;

    c->interval_start = 0;
    c->interval_end = 0;
    c->error = 0;

    c->value = calloc(length, sizeof(double));

    return c;
}

Coeficients *load_coeficients_from_file(char *path)
{
    FILE *f = fopen(path, "r");
    if (f == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int length = 0;
    fscanf(f, "%d", &length);

    Coeficients *c = build_coeficients(length);

    fscanf(f, "%lf %lf %lf", &c->interval_start, &c->interval_end, &c->error);

    for (int i = 0; i < length; i++)
    {
        fscanf(f, "%lf", &c->value[i]);
    }

    return c;
}

double quantify_coeficients(Coeficients *c, double x)
{
    double sum = c->value[0];

    for (int i = 1; i < c->length; i++)
    {
        sum = sum * x + c->value[i];
    }

    return sum;
}

double regula_falsi(Coeficients *c)
{
    double start_value = quantify_coeficients(c, c->interval_start);
    double end_value = quantify_coeficients(c, c->interval_end);

    return (end_value * c->interval_start) - (start_value * c->interval_end) / (start_value - end_value);
}
