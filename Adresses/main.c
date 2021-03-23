#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}

// 6 hexadecimals
bool is_valid_mac(char *str)
{
    int valid_len = 6 * 2 + 5;
    if (strlen(str) != valid_len)
    {
        return false;
    }

    for (int i = 1; i < 6; i++)
    {
        for (int j = 1; j < 2; j++)
        {
            char c = str[i * j]
        }
    }
}

bool is_valid_ipv4()
{
}

bool is_valid_ipv6()
{
}
