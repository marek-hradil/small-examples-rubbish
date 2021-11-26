#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float convert_to_float(int base, int exponent)
{
    return (float)base * powf(10, exponent);
}

int main(int argc, char *argv[])
{
    int base = 0;
    int exponent = 0;
    int scanned = scanf("%iE%i", &base, &exponent);

    if (scanned != 2 || (base == 0 && exponent == 0))
    {
        printf("NAN");
        return EXIT_FAILURE;
    }

    float converted = convert_to_float(base, exponent);
    printf("%.3f\n", converted);

    return EXIT_SUCCESS;
}