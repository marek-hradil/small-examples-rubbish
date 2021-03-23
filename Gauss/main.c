#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct
{
    int rows;
    int cols;
    float **value;
} Matrix;

enum MatrixResult
{
    Concrete,
    Infinite,
    None,
};

float calculate_multiplier(float base, float coeficient)
{
    return coeficient / base;
}

Matrix *init_matrix(int rows, int cols)
{
    Matrix *matrix = malloc(sizeof(Matrix));

    matrix->rows = rows;
    matrix->cols = cols;
    matrix->value = malloc(sizeof(float *) * matrix->rows);

    for (int i = 0; i < matrix->rows; i++)
    {
        matrix->value[i] = malloc(sizeof(float) * matrix->cols);
    }

    return matrix;
}

Matrix *load_matrix_from_file(FILE *input_file)
{
    int rows = 0;
    int cols = 0;
    if (fscanf(input_file, "%d %d", &rows, &cols) == 0)
    {
        fprintf(stderr, "Couldn't load matrix sizes. \n");
        exit(EXIT_FAILURE);
    }

    Matrix *matrix = init_matrix(rows, cols);

    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->cols; j++)
        {
            if (fscanf(input_file, "%f", &matrix->value[i][j]) == 0)
            {
                fprintf(stderr, "Too few input numbers given. \n");
                exit(EXIT_FAILURE);
            }
        }
    }

    return matrix;
}

void check_row_index(Matrix *matrix, int row_index)
{
    if (row_index < 0 || row_index >= matrix->rows)
    {
        fprintf(stderr, "Invalid row index supplied. \n");
        exit(EXIT_FAILURE);
    }
}

void check_col_index(Matrix *matrix, int col_index)
{
    if (col_index < 0 || col_index >= matrix->cols)
    {
        fprintf(stderr, "Invalid col index supplied. \n");
        exit(EXIT_FAILURE);
    }
}

Matrix *swap_matrix_rows(Matrix *matrix, int row_index_1, int row_index_2)
{
    check_row_index(matrix, row_index_1);
    check_row_index(matrix, row_index_2);

    if (row_index_1 == row_index_2)
    {
        return matrix;
    }

    float *temp = matrix->value[row_index_1];
    matrix->value[row_index_1] = matrix->value[row_index_2];
    matrix->value[row_index_2] = temp;

    return matrix;
}

int find_col_max_row_index(Matrix *matrix, int col_index)
{
    check_col_index(matrix, col_index);

    int max_row_index = 0;
    float max = matrix->value[0][col_index];

    for (int i = 1; i < matrix->rows; i++)
    {
        if (fabsf(matrix->value[i][col_index]) > fabsf(max))
        {
            max_row_index = i;
        }
    }

    return max_row_index;
}

Matrix *eliminate_rows(Matrix *matrix, int starting_point_row, int starting_point_col)
{
    check_row_index(matrix, starting_point_row);
    check_col_index(matrix, starting_point_col);

    int max_row_index = find_col_max_row_index(matrix, starting_point_col);
    if (max_row_index != starting_point_row)
    {
        swap_matrix_rows(matrix, max_row_index, starting_point_row);
    }

    for (int j = 1; j < (matrix->rows - starting_point_row); j++)
    {
        float multiplier = calculate_multiplier(matrix->value[starting_point_row][starting_point_col], matrix->value[starting_point_row + j][starting_point_col]);
        for (int i = starting_point_col; i < matrix->cols; i++)
        {
            if (i == starting_point_col)
            {
                matrix->value[starting_point_col + j][i] = 0;
            }
            else
            {
                matrix->value[starting_point_row + j][i] = matrix->value[starting_point_row + j][i] - (multiplier * matrix->value[starting_point_row][i]);
            }
        }
    }

    return matrix;
}

Matrix *perform_forward_elimination(Matrix *matrix)
{
    if (matrix->rows + 1 != matrix->cols)
    {
        fprintf(stderr, "Cannot perform forward elimination on this matrix.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < matrix->cols - 2; i++)
    {
        eliminate_rows(matrix, i, i);
    }

    return matrix;
}

enum MatrixResult test_for_result(Matrix *matrix)
{
    float exponent = matrix->value[matrix->rows - 1][matrix->cols - 2];
    float concrete_value = matrix->value[matrix->rows - 1][matrix->cols - 1];

    if (exponent == 0 && concrete_value == 0)
    {
        return Infinite;
    }
    else if (exponent == 0 && concrete_value > 0)
    {
        return None;
    }
    else
    {
        return Concrete;
    }
}

float *perform_backward_elimination(Matrix *matrix)
{
    float *results = malloc(sizeof(float) * matrix->cols);
    for (int i = matrix->rows - 1; i >= 0; i--)
    {
        float base = matrix->value[i][i];
        float absolute_value = matrix->value[i][matrix->cols - 1];
        float sum = 0;

        for (int j = i + 1; j < (matrix->cols - 1); j++)
        {
            sum += results[j] * matrix->value[i][j];
        }

        results[i] = (absolute_value - sum) / base;
    }

    return results;
}

void print_results(float *results, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Row %d: %f \n", i + 1, results[i]);
    }
}

void print_matrix_to_file(Matrix *matrix, FILE *output_file)
{
    fprintf(output_file, "%d %d\n", matrix->rows, matrix->cols);

    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->cols; j++)
        {
            fprintf(output_file, "%f ", matrix->value[i][j]);
        }

        fprintf(output_file, "\n");
    }
}

FILE *open_matrix_file(const char *path, const char *mode)
{
    FILE *matrix_file = fopen(path, mode);
    if (matrix_file == NULL)
    {
        fprintf(stderr, "Couldn't open matrix input file. \n");
        exit(EXIT_FAILURE);
    }

    return matrix_file;
}

int main()
{
    FILE *first_matrix_input_file = open_matrix_file("./assets/matice1.txt", "r");
    FILE *first_matrix_output_file = open_matrix_file("./assets/matice_output1.txt", "w");
    Matrix *matrix = load_matrix_from_file(first_matrix_input_file);

    perform_forward_elimination(matrix);

    print_matrix_to_file(matrix, first_matrix_output_file);

    switch (test_for_result(matrix))
    {
    case Concrete:
    {
        float *results = perform_backward_elimination(matrix);
        print_results(results, matrix->cols - 1);
        free(results);
    }
    break;

    case Infinite:
    {
        printf("Inifinite number of solutions. \n");
    }
    break;

    case None:
    {
        printf("No solution. \n");
    }
    }

    return EXIT_SUCCESS;
}