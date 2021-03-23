#include <stdio.h>
#include <stdlib.h>
#include <matrix_logic.h>
#include <math.h>
#include "linear_regression.h"
#include "matrix_logic.h"

CoordinatesArray *load_points_from_file(char *path)
{
    FILE *file = fopen(path, "r");
    if (file == NULL)
    {
        perror("Cannot open entry file, wrong path given.");
        exit(EXIT_FAILURE);
    }

    int allocated = 5;
    int counter = 0;

    CoordinatesArray *points_arr = malloc(sizeof(CoordinatesArray));
    Coordinates *points = malloc(sizeof(Coordinates) * allocated);

    while (fscanf(file, "%f %f", &points[counter].x, &points[counter].y) != EOF)
    {
        counter += 1;
        if (counter == allocated)
        {
            allocated += 5;
            points = realloc(points, sizeof(Coordinates) * allocated);
        }
    }

    points_arr->value = points;
    points_arr->length = counter;

    return points_arr;
}

Matrix *craft_linear_regression_matrix(CoordinatesArray *points)
{
    float sum_x = 0;
    float sum_pow_x = 0;
    float sum_multiple = 0;
    float sum_y = 0;

    for (int i = 0; i < points->length; i++)
    {
        sum_x += points->value[i].x;
        sum_y += points->value[i].y;
        sum_multiple += points->value[i].x * points->value[i].y;
        sum_pow_x += powf(points->value[i].x, 2);
    }

    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->rows = 2;
    matrix->cols = 3;

    matrix->value = malloc(sizeof(float *) * 2);
    matrix->value[0] = malloc(sizeof(float) * 3);
    matrix->value[1] = malloc(sizeof(float) * 3);

    matrix->value[0][0] = sum_pow_x;
    matrix->value[0][1] = sum_x;
    matrix->value[0][2] = sum_multiple;
    matrix->value[1][0] = sum_x;
    matrix->value[1][1] = points->length;
    matrix->value[1][2] = sum_y;

    return matrix;
}