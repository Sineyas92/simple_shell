#include "main.h"

/**
 * free2d - libère la mémoire d'un tableau 2D
 * @array: le tableau 2D à libérer.
 *
 * Retourne : rien
 */
void free2d(char **array)
{
int index = 0;
if (array == NULL)
return;
while (array[index])
{
free(array[index]);
array[index] = NULL;
index++; }
free(array);
array = NULL;
}

