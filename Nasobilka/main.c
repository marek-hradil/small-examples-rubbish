#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Invalid number of parameters provided. \n");
        return EXIT_FAILURE;
    }

    int count = strtol(argv[1], NULL, 10);
    if (errno != 0 && count == 0) {
        fprintf(stderr, "First parameter: %d, is unsuitable. \n", count);
        return EXIT_FAILURE;
    }

    int exponent = strtol(argv[2], NULL, 10);
    if (errno != 0 && exponent == 0) {
        fprintf(stderr, "Second parameter is unsuitable. \n");
        return EXIT_FAILURE;
    }


    for (int i = 1; i <= count; i++) {
        printf("%d * %d = %d\n", i, exponent, i * exponent);
    }

    return EXIT_SUCCESS;
}