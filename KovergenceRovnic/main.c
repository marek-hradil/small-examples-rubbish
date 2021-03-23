#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
• Ověř, zda je matice ostře diagonálně dominantní. 
• Ověř, zda řešení pomocí Jacobiho nebo Gauss-Seidelovy iterační metody bude nad touto maticí koeficientů konvergovat. 
*/

typedef struct
{
    int cols;
    int rows;
    float **value;
} Matrix;

Matrix *build_matrix(int rows, int cols)
{
    Matrix *m = malloc(sizeof(Matrix));

    if (m == NULL)
    {
        exit(EXIT_FAILURE);
    }

    m->rows = rows;
    m->cols = cols;

    m->value = calloc(m->rows, sizeof(float));
    for (int i = 0; i < m->rows; i++)
    {
        m->value[i] = calloc(m->cols, sizeof(float));
    }

    return m;
}

Matrix *load_matrix(char *path)
{
    FILE *f = fopen(path, "r");
    if (!f)
    {
        exit(EXIT_FAILURE);
    }

    int rows;
    int cols;
    fscanf(f, "%d %d", &rows, &cols);

    if (!rows || !cols)
    {
        exit(EXIT_FAILURE);
    }

    Matrix *m = build_matrix(rows, cols);

    for (int i = 0; i < m->rows; i++)
    {
        for (int j = 0; j < m->cols; j++)
        {
            fscanf(f, "%lf ", m->value[i][j]);
        }
    }

    return m;
}

bool is_matrix_dominant(Matrix *m)
{
    for (int i = 0; i < m->rows; i++)
    {
        float main_value = m->value[i][i];

        for (int j = 0; j < m->cols; j++)
        {
            if (m->value[i][j] > main_value && i != j)
            {
                return false;
            }
        }
    }

    return true;
}

int main(int argc, char *argv[])
{
    Matrix *m = load_matrix("./assets/matrix.txt");

    return EXIT_SUCCESS;
}