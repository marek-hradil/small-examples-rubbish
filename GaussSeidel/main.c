#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "matrix_io.h"
#include "matrix_logic.h"

// matrix_io
extern Matrix *load_matrix_from_file(char *path);
extern void delete_matrix(Matrix *matrix);

// matrix_logic
extern void gauss_seidel(Matrix *matrix, float accuarcy, int iteration_limit);

int main(int argc, char *argv[])
{
    errno = 0;

    if (argc < 3)
    {
        perror("Accuarcy and iteration limit parameters must be supplied.");

        return EXIT_FAILURE;
    }

    float accuarcy = strtof(argv[1], NULL);
    if (!accuarcy || errno == ERANGE)
    {
        perror("Accuarcy couldnt be converted to float.");

        return EXIT_FAILURE;
    }

    int iteration_limit = strtol(argv[2], NULL, 10);
    if (!iteration_limit || errno == ERANGE)
    {
        perror("Iteration limit couldnt be converted to integer.");

        return EXIT_FAILURE;
    }

    Matrix *matrix = load_matrix_from_file("./assets/rovnice.txt");
    gauss_seidel(matrix, accuarcy, iteration_limit);
    delete_matrix(matrix);

    return EXIT_SUCCESS;
}