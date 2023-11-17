#include "main.h"
/**
 * _strln.
 */
int _strlen(char *str)
{
    int count, inc;

    inc = 0;
    for (count = 0; str[count] != '\0'; count++)
        inc++;
    return (inc);
}

