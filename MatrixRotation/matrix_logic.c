#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>
#include "matrix_logic.h"

Matrix *rotate_matrix(Matrix *matrix)
{
    Matrix *transponed_matrix = malloc(sizeof(Matrix));
    if (transponed_matrix == NULL)
    {
        exit(EXIT_FAILURE);
    }

    transponed_matrix->rows = matrix->cols;
    transponed_matrix->cols = matrix->rows;
    transponed_matrix->value = calloc(matrix->cols, sizeof(float *));

    for (int i = 0; i < matrix->cols; i++)
    {
        transponed_matrix->value[i] = calloc(matrix->rows, sizeof(float));
    }

    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->cols; j++)
        {
            transponed_matrix->value[j][i] = matrix->value[i][j];
        }
    }

    float *temp[matrix->rows];
    for (int i = 0; i < matrix->rows; i++)
    {
        temp[matrix->rows - i - 1] = transponed_matrix->value[i];
    }

    for (int i = 0; i < matrix->rows; i++)
    {
        transponed_matrix->value[i] = temp[i];
    }

    return transponed_matrix;
}