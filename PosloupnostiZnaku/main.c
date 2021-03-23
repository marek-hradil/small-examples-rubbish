#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
• Dva vstupní soubory obsahují seřazené posloupnosti znaků. Sluč je do třetího vý stupního souboru tak, aby v něm byly všechny znaky také seřazeny.

int main(int argc, char *argv[])
{
    FILE *file_1 = fopen("./assets/file1.txt", "r");
    FILE *file_2 = fopen("./assets/file2.txt", "r");
    FILE *file_3 = fopen("./assets/file3.txt", "w");

    if (!file_1 || !file_2)
    {
        perror("Couldn't open input file");
        return EXIT_FAILURE;
    }

    char last_char_file_1 = 0;
    char last_char_file_2 = 0;

    for (;;)
    {
        if (!last_char_file_1)
        {
            last_char_file_1 = fgetc(file_1);
        }

        if (!last_char_file_2)
        {
            last_char_file_2 = fgetc(file_2);
        }

        if (last_char_file_1 == EOF && last_char_file_2 == EOF)
        {
            break;
        }

        if (last_char_file_1 == EOF || last_char_file_1 <= last_char_file_2)
        {
            fputc(last_char_file_2, file_3);
            last_char_file_2 = 0;
        }

        if (last_char_file_2 == EOF || last_char_file_1 > last_char_file_2)
        {
            fputc(last_char_file_1, file_3);
            last_char_file_1 = 0;
        }
    }

    fclose(file_1);
    fclose(file_2);
    fclose(file_3);

    return EXIT_SUCCESS;
}

• Dva vstupní soubory obsahují znaky. Sluč je do třetího výstupního souboru tak, aby v něm byly znaky seřazeny po dvojicích. 
• Vstupní soubor obsahuje posloupnost znaků. Rozděl je po N-ticích do dvou výstupních souborů (N je parametr). 
*/

int main(int argc, char *argv[])
{
    FILE *file_1 = fopen("./assets/file1.txt", "r");
    FILE *file_2 = fopen("./assets/file2.txt", "r");
    FILE *file_3 = fopen("./assets/file3.txt", "w");

    if (!file_1 || !file_2)
    {
        perror("Couldn't open input file");
        return EXIT_FAILURE;
    }

    fclose(file_1);
    fclose(file_2);
    fclose(file_3);

    return EXIT_SUCCESS;
}