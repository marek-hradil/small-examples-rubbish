#include <stdlib.h>
#include <stdio.h>
#include "matrix_io.h"
#include "matrix_logic.h"

extern Matrix *load_matrix_from_file(char *path);
extern void print_matrix_to_file(char *path, Matrix *matrix);
extern void apply_gauss_jordan(Matrix *matrix);
extern void delete_matrix(Matrix *matrix);

int main(int argc, char *argv[])
{
    Matrix *matrix = load_matrix_from_file("./assets/rovnice.txt");
    apply_gauss_jordan(matrix);
    print_matrix_to_file("./assets/rovince_result.txt", matrix);
    delete_matrix(matrix);

    return EXIT_SUCCESS;
}