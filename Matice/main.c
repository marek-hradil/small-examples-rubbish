#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int rows;
    int cols;
    float ** value;
} Matrix;

Matrix * init_matrix(int rows, int cols) {
    Matrix * matrix = malloc(sizeof(Matrix));

    matrix->rows = rows;
    matrix->cols = cols;
    matrix->value = malloc(sizeof(float *) * matrix->rows);

    for (int i = 0; i < matrix->rows; i++) {
        matrix->value[i] = malloc(sizeof(float) * matrix->cols);
    }

    return matrix;
}

Matrix * load_matrix_from_file(FILE * input_file) {
    int rows = 0;
    int cols = 0;
    if (fscanf(input_file, "%d %d", &rows, &cols) == 0) {
        fprintf(stderr, "Couldn't load matrix sizes. \n");
        exit(EXIT_FAILURE);
    }

    Matrix * matrix = init_matrix(rows, cols);

    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            if (fscanf(input_file, "%f", &matrix->value[i][j]) == 0) {
                fprintf(stderr, "Too few input numbers given. \n");
                exit(EXIT_FAILURE);
            }
        }
    }

    return matrix;
}

Matrix * add_matrixes(Matrix * matrix1, Matrix * matrix2) {
    if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
        fprintf(stderr, "Cant perform addition on different sized matrixes. \n");
        exit(EXIT_FAILURE);
    }

    Matrix * result_matrix = init_matrix(matrix1->rows, matrix2->cols);

    for (int i = 0; i < result_matrix->rows; i++) {
        for (int j = 0; j < result_matrix->cols; j++) {
            result_matrix->value[i][j] = matrix1->value[i][j] + matrix2->value[i][j];
        }
    }

    return result_matrix;
}

Matrix * multiply_matrixes(Matrix * matrix1, Matrix * matrix2) {
    if (matrix1->cols != matrix2->rows) {
        fprintf(stderr, "Cant perform addition on different sized matrixes. \n");
        exit(EXIT_FAILURE);
    }

    Matrix * result_matrix = init_matrix(matrix1->rows, matrix2->cols);
    for (int i = 0; i < result_matrix->rows; i++) {
        for (int j = 0; j < result_matrix->cols; j++) {
            for (int k = 0; k < matrix1->cols; k++) {
                result_matrix->value[i][j] = matrix1->value[i][k] + matrix2->value[k][j];
            }
        }
    }

    return result_matrix;
}

void print_matrix_to_file(Matrix * matrix, FILE * output_file) {
   fprintf(output_file, "%d %d\n", matrix->rows, matrix->cols);

   for (int i = 0; i < matrix->rows; i++) {
       for (int j = 0; j < matrix->cols; j++) {
           fprintf(output_file, "%f ", matrix->value[i][j]);
       }

       fprintf(output_file, "\n");
   }
}

FILE * open_matrix_file(const char * path, const char * mode) {
    FILE * matrix_file = fopen(path, mode);
    if (matrix_file == NULL) {
        fprintf(stderr, "Couldn't open matrix input file. \n");
        exit(EXIT_FAILURE);
    }

    return matrix_file;
}


int main() {
    FILE * first_matrix_input_file = open_matrix_file("./assets/matice1.txt", "r");
    FILE * first_matrix_output_file = open_matrix_file("./assets/matice_output1.txt", "w");
    FILE * second_matrix_input_file = open_matrix_file("./assets/matice2.txt", "r");
    FILE * third_matrix_input_file = open_matrix_file("./assets/matice3.txt", "r");
    FILE * addition_matrix_output_file = open_matrix_file("./assets/matice_output_soucet.txt", "w");
    FILE * multiplication_matrix_output_file = open_matrix_file("./assets/matice_output_soucin.txt", "w");

    Matrix * first_matrix = load_matrix_from_file(first_matrix_input_file);
    Matrix * second_matrix = load_matrix_from_file(second_matrix_input_file);
    Matrix * third_matrix = load_matrix_from_file(third_matrix_input_file);

    print_matrix_to_file(first_matrix, first_matrix_output_file);

    Matrix * addition_matrix = add_matrixes(first_matrix, third_matrix);
    print_matrix_to_file(addition_matrix, addition_matrix_output_file);

    Matrix * multiplication_matrix = multiply_matrixes(first_matrix, second_matrix);
    print_matrix_to_file(multiplication_matrix, multiplication_matrix_output_file);

    return EXIT_SUCCESS;
}