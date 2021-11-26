#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int rows;
    int cols;
    float **value;
} Matrix;

enum SolveabilityResult
{
    Regular,
    Infinite,
    None,
};

Matrix *build_matrix(int rows, int cols)
{
    Matrix *m = malloc(sizeof(Matrix));

    m->rows = rows;
    m->cols = cols;

    m->value = malloc(sizeof(float *) * rows);
    for (int i = 0; i < rows; i++)
    {
        m->value[i] = calloc(cols, sizeof(float));
    }

    return m;
}

void delete_matrix(Matrix *m)
{
    for (int i = 0; i < m->rows; i++)
    {
        free(m->value[i]);
    }

    free(m->value);
    free(m);
}

Matrix *load_matrix_from_file(char *path)
{
    FILE *f = fopen(path, "r");
    int rows = 0;
    int cols = 0;

    fscanf(f, "%d %d", &rows, &cols);

    Matrix *m = build_matrix(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            fscanf(f, "%F ", &m->value[i][j]);
        }
    }

    fclose(f);

    return m;
}

void print_matrix(Matrix *m)
{
    printf("\n");
    for (int i = 0; i < m->rows; i++)
    {
        for (int j = 0; j < m->cols; j++)
        {
            printf("%2.2F\t", m->value[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void swap_row(Matrix *m, int r1, int r2)
{
    float *tmp = m->value[r1];
    m->value[r1] = m->value[r2];
    m->value[r2] = tmp;
}

void perform_forward_elimination(Matrix *m)
{
    for (int i = 0; i < m->rows - 1; i++)
    {
        float diagonal_element_value = m->value[i][i];

        for (int j = i + 1; j < m->rows; j++)
        {
            float coef = m->value[j][i] / m->value[i][i];

            m->value[j][i] = 0;

            for (int k = i + 1; k < m->cols; k++)
            {
                m->value[j][k] = m->value[j][k] - (m->value[i][k] * coef);
            }
        }
    }
}

enum SolveabilityResult perform_solveability_check(Matrix *m)
{
    float last_exponent = m->value[m->rows - 1][m->cols - 2];
    float last_absolute = m->value[m->rows - 1][m->cols - 1];
    if (last_exponent != 0.0)
    {
        return Regular;
    }

    if (last_absolute == 0)
    {
        return Infinite;
    }

    return None;
}

void perform_backwards_propagation(Matrix *m)
{
    for (int i = m->rows - 1; i >= 0; i--)
    {
        float sum = 0;
        for (int j = i + 1; j < m->cols - 1; j++)
        {
            sum += m->value[i][j] * m->value[j][m->cols - 1];
            m->value[i][j] = 0;
        }

        float absolute = m->value[i][m->cols - 1];
        float expo = m->value[i][i];

        m->value[i][m->cols - 1] = (absolute - sum) / expo;
        m->value[i][i] = 1;
    }
}

int main(int argc, char *argv[])
{
    Matrix *m = load_matrix_from_file("./assets/matice1.txt");
    print_matrix(m);
    perform_forward_elimination(m);
    print_matrix(m);
    perform_backwards_propagation(m);
    print_matrix(m);
    delete_matrix(m);
    return EXIT_SUCCESS;
}