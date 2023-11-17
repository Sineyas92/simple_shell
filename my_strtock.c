#include "main.h"

/**
 * tokenizeString - extrait des jetons d'un tampon.
 * @inputString: tampon d'entrée.
 *
 * Retourne : les jetons.
 */
char **tokenizeString(char *inputString)
{
    char *token, **tokens, *temp;
    int tokenCount, i;

    tokens = NULL;
    token = NULL;
    tokenCount = 0;
    i = 0;
    temp = NULL;

    if (!inputString)
        return NULL;

    temp = _strdup(inputString);
    token = strtok(temp, " \t\n");

    if (token == NULL)
    {
        free(inputString);
        free(temp);
        return NULL;
    }

    while (token)
    {
        tokenCount++;
        token = strtok(NULL, " \t\n");
    }

    free(temp);
    tokens = malloc(sizeof(char *) * (tokenCount + 1));

    if (!tokens)
    {
        free(inputString);
        return NULL;
    }

    token = strtok(inputString, " \t\n");

    while (token)
    {
        tokens[i] = _strdup(token);
        token = strtok(NULL, " \t\n");
        i++;
    }

    free(inputString);
    tokens[i] = NULL;
    return tokens;
}

