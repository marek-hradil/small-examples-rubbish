#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bit_and(char bits1[], char bits2[], char res[])
{
    int len1 = strlen(bits1);
    int len2 = strlen(bits2);

    if (len1 < len2)
    {
        fprintf(stderr, "Pass higher number first");
        exit(EXIT_FAILURE);
    }

    for (int i = len1 - 1; i >= 0; i--)
    {
        char bit1 = bits1[i];
        char bit2 = bits2[i];

        if (bit1 == '1' && bit2 == '1')
        {
            res[i] = '1';
        }
        else
        {
            res[i] = '0';
        }
    }
}

void bit_or(char bits1[], char bits2[], char res[])
{
    int len1 = strlen(bits1);
    int len2 = strlen(bits2);

    if (len1 < len2)
    {
        fprintf(stderr, "Pass higher number first");
        exit(EXIT_FAILURE);
    }

    for (int i = len1 - 1; i >= 0; i--)
    {
        char bit1 = bits1[i];
        char bit2 = bits2[i];

        if (bit1 == '0' && bit2 == '0')
        {
            res[i] = '0';
        }
        else
        {
            res[i] = '1';
        }
    }
}

void bit_rotate_left(int shift, char bits[], char res[])
{
    int len = strlen(bits);

    for (int i = len - 1; i >= 0; i--)
    {
        char bit = bits[i];

        res[abs((i - shift) % len)] = bit;
    }
}

int main(int argc, char *argv[])
{

    int len = strlen(argv[1]);
    char bits[len];
    char res[len];

    strcpy(bits, argv[1]);

    res[len] = '\0';

    bit_rotate_left(1, bits, res);

    printf("%s", res);
    /*
    if (argc < 3)
    {
        fprintf(stderr, "Parameters not supplied");
        return EXIT_FAILURE;
    }

    int len1 = strlen(argv[1]);
    int len2 = strlen(argv[2]);
    int len_res = len1 >= len2 ? len1 : len2;
    char bits1[len1];
    char bits2[len2];
    char res[len_res];

    strcpy(bits1, argv[1]);
    strcpy(bits2, argv[2]);

    res[len_res] = '\0';

    if (len1 >= len2)
    {
        bit_or(bits1, bits2, res);
    }
    else
    {
        bit_or(bits2, bits1, res);
    }

    printf("%s \n", res);

*/
    return EXIT_SUCCESS;
}