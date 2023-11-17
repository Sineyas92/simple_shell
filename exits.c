#include "shell.h"

char *_strncpy(char *destination, char *source, int num)
{
    int i, j;
    char *result = destination;

    i = 0;
    while (source[i] != '\0' && i < num - 1)
    {
        destination[i] = source[i];
        i++;
    }
    if (i < num)
    {
        j = i;
        while (j < num)
        {
            destination[j] = '\0';
            j++;
        }
    }
    return result;
}

char *_strncat(char *destination, char *source, int num)
{
    int i, j;
    char *result = destination;

    i = 0;
    j = 0;
    while (destination[i] != '\0')
        i++;
    while (source[j] != '\0' && j < num)
    {
        destination[i] = source[j];
        i++;
        j++;
    }
    if (j < num)
        destination[i] = '\0';
    return result;
}

char *_strchr(char *string, char character)
{
    do
    {
        if (*string == character)
            return string;
    } while (*string++ != '\0');

    return NULL;
}

