#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// • skryj v řetězci každé číslo přepsáním pomocí znaku #
/*
int main(int argc, char *argv[])
{
    char c;

    while ((c = getc(stdin)) != EOF)
    {
        if (isdigit(c))
        {
            printf("#");
        }
        else
        {
            printf("%c", c);
        }
    }

    return EXIT_SUCCESS;
}
*/

/*
// • vrať počet slov v řetězci
int main(int argc, char *argv[])
{

    char c;
    bool is_last_char_alpha = false;
    int count = 0;

    while ((c = getc(stdin)) != EOF)
    {
        if (isblank(c))
        {
            if (is_last_char_alpha)
            {
                count += 1;
            }

            is_last_char_alpha = false;
        }
        else
        {
            is_last_char_alpha = true;
        }
    }

    printf("count: %d", count);

    return EXIT_SUCCESS;
}

anebo 

int main(int argc, char *argv[])
{
    printf("count is: %d", argc - 1);

    return EXIT_SUCCESS;
}
*/

//• nahraď v řetězci malá písmena za velká, nebo velká za malá

/*
int main(int argc, char *argv[])
{
    char c;
    char newchar;

    while ((c = getc(stdin)) != EOF)
    {
        if (islower(c))
        {
            newchar = toupper(c);
        }
        else if (isupper(c))
        {
            newchar = tolower(c);
        }
        else
        {
            newchar = c;
        }

        putc(newchar, stdout);
    }

    return EXIT_SUCCESS;
}
*/

// • proveď reverzi řetězce jednou pomocí rekurze a jednou pomocí cyklu s co nej menším počtem iterací

/*
void print_reversed_cyclic(char str[], int length)
{
    for (int i = length - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
}

void print_reversed_recursive(char str[], int length)
{
    printf("%c", str[length - 1]);
    if (length != 1)
    {
        print_reversed_recursive(str, length - 1);
    }
}

int main(int argc, char *argv[])
{
    char *str = argv[1];
    int length = strlen(str);
    char str_arr[length];
    strcpy(str_arr, str);

    print_reversed_recursive(str_arr, length);
}
*/