#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hex_char_to_int(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }

    if (c >= 'A' && c <= 'F')
    {
        return c - 'A' + 10;
    }

    if (c >= 'a' && c <= 'f')
    {
        return c - 'a' + 10;
    }

    return -1;
}

int *enumerate_hex_to_coefs(char *str)
{
    int *coefs = malloc(sizeof(int) * strlen(str));
    if (coefs == NULL)
    {
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < strlen(str); i++)
    {
        coefs[i] = hex_char_to_int(str[i]);

        if (coefs[i] == -1)
        {
            exit(EXIT_FAILURE);
        }
    }

    return coefs;
}

float horner_scheme(int *coefs, int n, int base)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum *= base;
        sum += coefs[i];
    }

    return sum;
}

int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}