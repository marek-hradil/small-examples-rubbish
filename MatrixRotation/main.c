#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int rows;
    int cols;
    int **value;
} Matrix;

Matrix *build_matrix(int rows, int cols)
{
    Matrix *matrix = malloc(sizeof(Matrix));
    for (int i = 0; i < matrix->rows; i++)
    {
        matrix->value[i] = malloc(sizeof(int) * matrix->cols);
    }

    return matrix;
}

Matrix *rotate_matrix(Matrix *matrix)
{
    Matrix *new_matrix = build_matrix(matrix->rows, matrix->cols);
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->cols; j++)
        {
            new_matrix->value[i][j] = matrix->value[(j + matrix->rows) % matrix->rows][(i + matrix->cols) % matrix->cols];
        }
    }

    return new_matrix;
}

Matrix *load_matrix_from_file(char *path)
{
    FILE *f = fopen(path, "r");
    if (f == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int rows = 0;
    int cols = 0;
    int loaded = fscanf(f, "%d %d", &rows, &cols);
    if (loaded != 2)
    {
        exit(EXIT_FAILURE);
    }

    Matrix *matrix = build_matrix(rows, cols);

    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->cols; j++)
        {
            fscanf(f, "%d ", &matrix->value[i][j]);
        }
    }

    fclose(f);

    return matrix;
}

int main(int argc, char *argv[])
{
    Matrix *m = load_matrix_from_file("./assets/matrix.txt");
    for (int i = 0; i < m->rows; i++)
    {
        for (int j = 0; j < m->cols; j++)
        {
            printf("%d", m->value[i][j]);
        }

        printf("\n");
    }

    Matrix *nm = rotate_matrix(m);

    for (int i = 0; i < nm->rows; i++)
    {
        for (int j = 0; j < nm->cols; j++)
        {
            printf("%d", nm->value[i][j]);
        }

        printf("\n");
    }

    return EXIT_SUCCESS;
}