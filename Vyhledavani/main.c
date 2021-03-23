#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
• Vytvoř podprogram, který zpracuje vstupní soubor tak, že každý výskyt znaku # nahradí zadaným textovým řetězcem a výsledek zapíše do výstupního souboru.

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        perror("Couldnt get input string");
        return EXIT_FAILURE;
    }

    char c;
    while ((c = fgetc(stdin)) != EOF)
    {
        if (c == '#')
        {
            fputs(argv[1], stdout);
        }
        else
        {
            fputc(c, stdout);
        }
    }

    return EXIT_SUCCESS;
}
*/

/*
• Vytvoř podprogram, který zkombinuje dva vstupní soubory tak, že bude do výstupního souboru zapisovat střídavě vždy jeden řádek z prvního a pak ze druhé ho souboru.  
• Vytvoř podprogram, který zjistí počet slov na každém řádku vstupního souboru a tyto počty zapíše na odpovídající řádky výstupního souboru. 
• Vstupní soubor obsahuje textově zapsaná celá čísla větší než nula. Na začátku jsou data seřazená vzestupně na konci je oblast přeplnění. Seřazenou oblast a oblast přeplnění odděluje řádek s hodnotou 0. Vytvoř funkci, která v tomto sou boru efektivně vyhledá zadanou hodnotu a bude brát v úvahu jak seřazenou ob last, tak oblast přeplnění.
*/

int main(int argc, char *argv[])
{
    FILE *f1 = fopen("./assets/file.txt", "r");
    FILE *f2 = fopen("./assets/file2.txt", "r");
    if (!f1 || !f2)
    {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void combine(FILE *f1, FILE *f2)
{
}