#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool is_hexdec(char c)
{
    int val = (int)c;
    if (val >= 97 && val <= 102)
    {
        return true;
    }

    if (val >= 48 && val <= 57)
    {
        return true;
    }

    return false;
}

// 6 * 2 hexadecimals + :
bool is_valid_mac(char *str)
{
    if (strlen(str) != 17)
    {
        return false;
    }

    for (int i = 0; i < 17; i++)
    {
        if ((i + 1) % 3 == 0 && str[i] != ':')
        {
            return false;
        }

        if ((i + 1) % 3 != 0 && !is_hexdec(str[i]))
        {
            return false;
        }
    }

    return true;
}

// 4 bytes
bool is_valid_ipv4(char *s)
{
    char str[strlen(s)];
    strcpy(str, s);

    char *token = strtok(str, ".");
    int count = 0;
    while (token != NULL)
    {
        if (count > 4)
        {
            return false;
        }

        int value = atoi(token);
        if (value < 0 || value > 255)
        {
            return false;
        }

        count += 1;
        token = strtok(NULL, ".");
    }

    return true;
}

/*
// 4 hexadecimals * 8
bool is_valid_ipv6()
{
}
*/

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return EXIT_FAILURE;
    }

    char *str = argv[1];

    bool is_mac = is_valid_mac(str);
    if (is_mac)
    {
        printf("Its valid MAC address\n");
    }
    else
    {
        printf("Its not valid MAC address\n");
    }

    bool is_valid_ip = is_valid_ipv4(str);
    if (is_valid_ip)
    {
        printf("Its valid ipv4 \n");
    }
    else
    {
        printf("Its not valid ipv4\n");
    }

    return EXIT_SUCCESS;
}