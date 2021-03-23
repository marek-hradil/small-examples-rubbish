#include <stdio.h>
#include <stdlib.h>

void replace_char_with_string(FILE *in, FILE *out, char c, char *str)
{
    char next;
    while ((next = fgetc(in)) != EOF)
    {
        if (next == c)
        {
            fputs(str, out);
        }
        else
        {
            fputc(next, out);
        }
    }
}

void combine_files(FILE *in1, FILE *in2, FILE *out)
{
    char line1[100];
    char line2[100];

    while (fscanf(in1, "%99[^\n]", line1) != EOF && fscanf(in2, "%99[^\n]", line2) != EOF)
    {
        fputs(line1, out);
        fputc('\n', out);
        fputs(line2, out);
        fputc('\n', out);
    }

    while (fscanf(in1, "%99[^\n]", line1) != 0)
    {
        fputs(line1, out);
    }

    while (fscanf(in2, "%99[^\n]", line2) != 0)
    {
        fputs(line2, out);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        perror("No file paths supplied.");
        return EXIT_FAILURE;
    }

    char *in_path = argv[1];
    char *out_path = argv[2];

    FILE *in = fopen(in_path, "r");
    FILE *in2 = fopen("./assets/in2.txt", "r");
    FILE *out = fopen(out_path, "w");

    if (in == NULL || out == NULL || in2 == NULL)
    {
        perror("Couldn't find the file");
        return EXIT_FAILURE;
    }

    combine_files(in, in2, out);

    fclose(in);
    fclose(in2);
    fclose(out);

    return EXIT_SUCCESS;
}