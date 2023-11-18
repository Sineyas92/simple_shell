#include "main.h"

/**
 *_strlen - returns the length of a string
 * @str: string
 *
 *Return: returns lenght;
 */
int _strlen(char *str)
{
    int count, inc;

    inc = 0;
    for (count = 0; str[count] != '\0'; count++)
        inc++;
    return (inc);
}

