#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include <errno.h>
#include <getopt.h>

#include "matrix_io.h"
#include "matrix_logic.h"

// matrix_io
extern Matrix *load_matrix_from_file(char *path);
extern void delete_matrix(Matrix *matrix);

// matrix_logic
extern void jacobi(Matrix *matrix, float accuarcy, int iteration_limit);

int main(int argc, char *argv[])
{
    errno = 0;

    static struct option long_options[] = {
        {"help", optional_argument, 0, 'h'},
        {"accuarcy", required_argument, 0, 'a'},
        {"iterations", required_argument, 0, 'i'},
        {NULL, 0, NULL, 0},
    };

    char option;

    float opt_accuarcy = 0.0;
    int opt_iterations = 0;

    while ((option = getopt_long(argc, argv, "a:i:h", long_options, NULL)) != -1)
    {
        switch (option)
        {
        case 'h':
        {
            printf(
                "Usage:\n"
                "   -h | --help:      Print help\n"
                "   -a | --accuarcy:    Set accuarcy\n"
                "   -i | --iterations:  Set iteration limit\n");
        }
        break;

        case 'a':
        {
            errno = 0;
            opt_accuarcy = strtof(optarg, NULL);
            if (!opt_accuarcy || errno == ERANGE)
            {
                perror("Accuarcy couldnt be converted to float.");

                return EXIT_FAILURE;
            }
        }
        break;

        case 'i':
        {
            errno = 0;
            opt_iterations = strtol(optarg, NULL, 10);
            if (!opt_iterations || errno == ERANGE)
            {
                perror("Iteration limit couldnt be converted to integer.");

                return EXIT_FAILURE;
            }
        }
        break;

        case '?':
            perror("Unknown argument");
            return EXIT_FAILURE;
        }
    }

    if (opt_accuarcy == 0)
    {
        perror("Accuarcy wasnt provided.");

        return EXIT_FAILURE;
    }

    if (opt_iterations == 0)
    {
        perror("Iteration limit wasnt provided.");

        return EXIT_FAILURE;
    }

    Matrix *matrix = load_matrix_from_file("./assets/rovnice.txt");
    jacobi(matrix, opt_accuarcy, opt_iterations);
    delete_matrix(matrix);

    return EXIT_SUCCESS;
}