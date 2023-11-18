#include "main.h"

/**
 * my_getline - Lit une ligne depuis un flux de fichiers.
 *
 * Return: lineBuffer.
 */
char *my_getline(void)
{
    int numberOfChars;
    size_t bufferSize;
    char *lineBuffer;

    bufferSize = 0;
    lineBuffer = NULL;

    if (isatty(STDIN_FILENO))
        write(1, "#cisfun$ ", 9);

    numberOfChars = getline(&lineBuffer, &bufferSize, stdin);

    if (numberOfChars == -1)
    {
        free(lineBuffer);
        return NULL;
    }

    return lineBuffer;
}

