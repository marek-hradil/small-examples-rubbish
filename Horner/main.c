#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float horner_scheme(float coef[], int n, float x)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum *= x;
        sum += coef[i];
    }

    return sum;
}

float find_root_regula_falsi(float coef[], int n, float accuarcy, float start, float end)
{
    if (start * end > 0)
    {
        exit(EXIT_FAILURE);
    }

    float start_value = horner_scheme(coef, n, start);
    float end_value = horner_scheme(coef, n, end);

    float result_value = (start_value * (end - start) / start_value - end_value) + start;

    if (result_value < accuarcy)
    {
        return result_value;
    }

    if (start_value * result_value)
    {
        return find_root_regula_falsi(coef, n, accuarcy, result_value, end_value);
    }
    else
    {
        return find_root_regula_falsi(coef, n, accuarcy, start_value, result_value);
    }
}

float find_root_bisection(float coef[], int n, float accuarcy, float start, float end)
{
    // perform check
    if (start * end > 0)
    {
        exit(EXIT_FAILURE);
    }

    float middle = (start + end) / 2;
    float middle_value = horner_scheme(coef, n, middle);

    if (fabsf(middle_value) < accuarcy)
    {
        return middle_value;
    }

    float start_value = horner_scheme(coef, n, start);

    if (start_value * middle_value > 0)
    {
        return find_root_bisection(coef, n, accuarcy, middle, end);
    }
    else
    {
        return find_root_bisection(coef, n, accuarcy, start, middle);
    }
}

int main(int argc, char *argv[])
{
    // x^2 + 2x^1 + 5
    float coef[3] = {1.0, 2.0, 5.0};
    float res = horner_scheme(coef, 3, 2);
    printf("%f", res);
    return EXIT_SUCCESS;
}
