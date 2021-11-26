#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_correct_letter(char c)
{
    int first_letter = 'a';
    int last_letter = 'z';

    if ((int)c < first_letter || (int)c > last_letter)
    {
        return false;
    }

    return true;
}

int get_pos_in_histogram(char c)
{
    return (int)c - 'a';
}

void print_histogram(int histogram[], int len)
{
    printf("-------\n");
    for (int i = 0; i < len; i++)
    {
        char letter = 'a' + i;
        printf("%c: %d \n", letter, histogram[i]);
    }
    printf("-------\n");
}

int main(int argv, char *argc[])
{
    int first_letter = 'a';
    int last_letter = 'z';

    int len = last_letter - first_letter + 1;
    int histogram[len];
    for (int i = 0; i < len; i++)
    {
        histogram[i] = 0;
    }

    bool should_continue = true;
    do
    {
        char c;
        int scanned_count = scanf("%c ", &c);

        if (scanned_count == 1 && is_correct_letter(c))
        {
            int pos = get_pos_in_histogram(c);

            histogram[pos] += 1;
        }
        else
        {
            print_histogram(histogram, len);
            should_continue = false;
        }
    } while (should_continue);

    return EXIT_SUCCESS;
}