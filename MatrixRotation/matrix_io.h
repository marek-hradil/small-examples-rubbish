#ifndef MATRIX_IO_H
#define MATRIX_IO_H

typedef struct
{
    int rows;
    int cols;
    float **value;
} Matrix;

Matrix *load_matrix_from_file(char *path);
void print_matrix_to_file(char *path, Matrix *matrix);
void delete_matrix(Matrix *matrix);

#endif
