#include "main.h"
/**
 * _strdup - returns a pointer to a newly allocated
 * space in memory, which contains a copy of the
 * string given as a parameter.
 * @str:String to be copied
 *
 * Return: NULL in case of error, pointer to allocated
 * space
 */
char *_str_duplicate(char *original_str)
{
    char *copy;
    int index, length;

    length = 0;

    if (original_str == NULL)
        return NULL;

    for (index = 0; original_str[index]; index++)
        length++;

    copy = malloc(sizeof(char) * (length + 1));

    if (copy == NULL)
        return NULL;

    for (index = 0; original_str[index]; index++)
    {
        copy[index] = original_str[index];
    }

    copy[length] = '\0';

    return copy;
}

