#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "matrix_logic.h"

static void _eliminate_rows(Matrix *matrix, int base_row_index, int solve_row_index)
{
    float *base_row = matrix->value[base_row_index];
    float *solve_row = matrix->value[solve_row_index];
    float multiplier = -solve_row[base_row_index] / base_row[base_row_index];

    solve_row[base_row_index] = 0;

    for (int i = base_row_index + 1; i < matrix->cols; i++)
    {
        solve_row[i] += base_row[i] * multiplier;
    }
}

static void eliminate_rows(Matrix *matrix, int base_row_index, int solve_row_index)
{
    assert(matrix != NULL);
    if (base_row_index == solve_row_index)
    {
        return;
    }

    _eliminate_rows(matrix, base_row_index, solve_row_index);
}

static Result **_select_results(Matrix *matrix)
{
    Result **results = malloc(sizeof(Result) * matrix->rows);
    assert(results != NULL);

    for (int i = 0; i < matrix->rows; i++)
    {
        Result *r = malloc(sizeof(Result));
        assert(r != NULL);

        float absolute_item = matrix->value[i][matrix->cols - 1];
        float base = matrix->value[i][i];

        if (base == 0 && absolute_item == 0)
        {
            r->type = Infinite;
        }
        else if (base == 0)
        {
            r->type = None;
        }
        else
        {
            r->type = Concrete;
            r->value = absolute_item / base;
        }

        results[i] = r;
    }

    return results;
}

static Result **select_results(Matrix *matrix)
{
    assert(matrix != NULL);

    return _select_results(matrix);
}

static void _apply_gauss_jordan(Matrix *matrix)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->rows; j++)
        {
            eliminate_rows(matrix, i, j);
        }
    }

    printf("--------------------------------------\n");

    Result **results = select_results(matrix);
    for (int i = 0; i < matrix->rows; i++)
    {
        switch (results[i]->type)
        {
        case Concrete:
            printf("Row %d: %f\n", i + 1, results[i]->value);
            break;
        case Infinite:
            printf("Row %d: Infinite number of solutions\n", i + 1);
            break;
        case None:
            printf("Row %d: None solution\n", i + 1);
        }

        free(results[i]);
    }

    printf("--------------------------------------\n");

    free(results);
}

void apply_gauss_jordan(Matrix *matrix)
{
    assert(matrix != NULL);
    _apply_gauss_jordan(matrix);
}