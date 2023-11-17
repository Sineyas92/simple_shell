#include "main.h"

/**
 * free2DArray - libère la mémoire d'un tableau 2D
 * @array: le tableau 2D à libérer.
 *
 * Retourne : rien
 */
void free2DArray(char **array)
{
    int index;

    if (array == NULL)
        return;

    for (index = 0; array[index]; index++)
    {
        free(array[index]);
        array[index] = NULL;
    }

    free(array);
    array = NULL;
}

