#ifndef MATRIX_LOGIC_H
#define MATRIX_LOGIC_H
#include "matrix_io.h"

typedef enum
{
    Concrete,
    Infinite,
    None
} ResultType;

typedef struct
{
    float value;
    ResultType type;
} Result;

void apply_gauss_jordan(Matrix *matrix);

#endif
