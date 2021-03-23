#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>
#include "matrix_logic.h"

inline static float _sum_row_absolute_coeficients(Matrix *matrix, int row_index)
{
    float sum = 0;
    for (int i = 0; i < matrix->cols - 1; i++)
    {
        sum += fabsf(matrix->value[row_index][i]);
    }

    return sum;
}

static float sum_row_absolute_coeficients(Matrix *matrix, int row_index)
{
    assert(matrix != NULL && matrix->cols > matrix->rows);
    assert(row_index < matrix->rows);

    return _sum_row_absolute_coeficients(matrix, row_index);
}

inline static bool _is_diagonally_dominant(Matrix *matrix)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        float diagonal_elem = fabsf(matrix->value[i][i]);
        float row_sum = sum_row_absolute_coeficients(matrix, i) - diagonal_elem;

        if (diagonal_elem <= row_sum)
        {
            return false;
        }
    }

    return true;
}

static bool is_diagonally_dominant(Matrix *matrix)
{
    assert(matrix != NULL && matrix->cols > matrix->rows);

    return _is_diagonally_dominant(matrix);
}

inline static void _prepare_for_gauss_seidel(Matrix *matrix)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        float *row = matrix->value[i];
        float divider = row[i];
        for (int j = 0; j < matrix->cols; j++)
        {
            row[j] /= divider;
        }

        row[i] = 0;
    }
}

static void prepare_for_gauss_seidel(Matrix *matrix)
{
    assert(matrix != NULL && matrix->cols > matrix->rows);
    _prepare_for_gauss_seidel(matrix);
}

inline static void _jacobi(Matrix *matrix, float accuarcy, int iteration_limit)
{
    bool is_accurate = false;
    float *prev_results = calloc(matrix->rows, sizeof(float));
    float *results = calloc(matrix->rows, sizeof(float));

    if (results == NULL)
    {
        perror("Couldn't allocate memory for matrix results");
        exit(EXIT_FAILURE);
    }

    if (prev_results == NULL)
    {
        perror("Couldn't allocate memory for prev_results");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; !is_accurate && i < iteration_limit; i++)
    {
        is_accurate = true;
        for (int j = 0; j < matrix->rows; j++)
        {
            float *row = matrix->value[j];
            float absolute_element = row[matrix->cols - 1];
            float sum = 0;

            for (int k = 0; k < matrix->cols; k++)
            {
                sum += row[k] * prev_results[k];
            }

            float new_value = absolute_element - sum;
            float accuarcy_error = fabsf(results[j] - new_value);

            is_accurate &= accuarcy_error < accuarcy;
            results[j] = new_value;
        }

        for (int j = 0; j < matrix->rows; j++)
        {
            prev_results[j] = results[j];
        }
    }

    if (!is_accurate)
    {
        perror(
            "Iteration limit exceeded. The system of equations either doesn't converge "
            "or iteration limit is too small to achieve the desired accuarcy.");
        free(prev_results);
        free(results);

        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < matrix->rows; i++)
    {
        printf("Row %d: %f\n", i, results[i]);
    }

    free(prev_results);
    free(results);
}

void jacobi(Matrix *matrix, float accuarcy, int iteration_limit)
{
    assert(matrix != NULL && matrix->cols > matrix->rows);
    assert(accuarcy > 0);
    assert(iteration_limit > 0);

    if (!is_diagonally_dominant(matrix))
    {
        perror(
            "Cannot perform gauss seidel iteration method on matrix, "
            "that is not strictly diagonally dominant");
        exit(EXIT_FAILURE);
    }

    prepare_for_gauss_seidel(matrix);
    _jacobi(matrix, accuarcy, iteration_limit);
}
