#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

typedef struct
{
    float x;
    float y;
} Coordinates;

typedef struct
{
    Coordinates *value;
    int length;
} CoordinatesArray;

Matrix *craft_linear_regression_matrix(CoordinatesArray *points);
CoordinatesArray *load_points_from_file(char *path);

#endif
