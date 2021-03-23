#include <stdlib.h>
#include <stdio.h>
#include "matrix_io.h"
#include "matrix_logic.h"
#include "linear_regression.h"

extern Result **apply_gauss_jordan(Matrix *matrix);
extern void delete_matrix(Matrix *matrix);
extern Matrix *craft_linear_regression_matrix(CoordinatesArray *points);
extern CoordinatesArray *load_points_from_file(char *path);

int main(int argc, char *argv[])
{
    CoordinatesArray *points = load_points_from_file("./assets/points.txt");
    Matrix *matrix = craft_linear_regression_matrix(points);
    Result **results = apply_gauss_jordan(matrix);

    float a = results[0]->value;
    float b = results[1]->value;

    printf("%.2fx + %.2f = y", a, b);

    delete_matrix(matrix);
    free(results);

    return EXIT_SUCCESS;
}