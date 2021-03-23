#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "matrix_io.h"
#include "matrix_logic.h"

// matrix_io
extern Matrix *load_matrix_from_file(char *path);
extern void delete_matrix(Matrix *matrix);

int main(int argc, char *argv[])
{
    Matrix *matrix = load_matrix_from_file("./assets/rovnice.txt");
    Matrix *transponed_matrix = rotate_matrix(matrix);

    print_matrix_to_file("./assets/output.txt", transponed_matrix);

    delete_matrix(matrix);
    delete_matrix(transponed_matrix);

    return EXIT_SUCCESS;
}