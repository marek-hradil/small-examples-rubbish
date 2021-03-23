#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "matrix_io.h"

static void _delete_matrix(Matrix *matrix)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        free(matrix->value[i]);
    }

    free(matrix);
}

void delete_matrix(Matrix *matrix)
{
    assert(matrix != NULL);
    _delete_matrix(matrix);
}

static void _fill_matrix_from_file(FILE *f, Matrix *matrix)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->cols; j++)
        {
            if (fscanf(f, "%f", &matrix->value[i][j]) != 1)
            {
                perror("Couldn't load matrix item");
                exit(EXIT_FAILURE);
            }
        }
    }
}

static void fill_matrix_from_file(FILE *f, Matrix *matrix)
{
    assert(f != NULL);
    assert(matrix != NULL);

    return _fill_matrix_from_file(f, matrix);
}

static Matrix *_load_matrix_from_file(FILE *f)
{
    Matrix *matrix = malloc(sizeof(Matrix));
    assert(matrix != NULL);

    if (fscanf(f, "%d %d", &matrix->rows, &matrix->cols) != 2)
    {
        perror("Couldn't load sizes params from file");
        exit(EXIT_FAILURE);
    }

    matrix->value = malloc(sizeof(float *) * matrix->rows);
    assert(matrix->value != NULL);

    for (int i = 0; i < matrix->rows; i++)
    {
        float *col = malloc(sizeof(float) * matrix->cols);
        assert(col != NULL);
        matrix->value[i] = col;
    }

    fill_matrix_from_file(f, matrix);

    return matrix;
}

Matrix *load_matrix_from_file(char *path)
{
    assert(path != NULL);
    FILE *f = fopen(path, "r");
    if (f == NULL)
    {
        perror("Couldn't open matrix file for reading");
        exit(EXIT_FAILURE);
    }

    return _load_matrix_from_file(f);
}

static void _print_matrix_to_file(FILE *f, Matrix *matrix)
{
    fprintf(f, "%d %d\n", matrix->rows, matrix->cols);

    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->cols; j++)
        {
            fprintf(f, "%f ", matrix->value[i][j]);
        }

        fprintf(f, "\n");
    }
}

void print_matrix_to_file(char *path, Matrix *matrix)
{
    assert(path != NULL);
    assert(matrix != NULL);

    FILE *f = fopen(path, "w");
    if (f == NULL)
    {
        perror("Couldn't open matrix file for writing");
        exit(EXIT_FAILURE);
    }

    _print_matrix_to_file(f, matrix);
}
