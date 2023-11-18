#include "main.h"

/**
 * my_strtok - extract tokens from a buffer.
 * @inputBuffer: input buffer.
 *
 * Return: tokens.
 */

char **my_strtok(char *inputBuffer)
{
char *currentToken, **tokens, *tempBuffer;
int count, i;
tokens = NULL;
currentToken = NULL;
count = 0;
i = 0;
tempBuffer = NULL;
if (!inputBuffer)
return (NULL);
tempBuffer = _strdup(inputBuffer);
currentToken = strtok(tempBuffer, " \t\n");	
if (currentToken == NULL)
{
free(inputBuffer), inputBuffer = NULL;
free(tempBuffer), tempBuffer = NULL;
return (NULL);
}
while (currentToken)
{
count++;
currentToken = strtok(NULL, " \t\n");
}
free(tempBuffer), tempBuffer = NULL;
tokens = malloc(sizeof(char *) * (count + 1));
if (!tokens)
{
free(inputBuffer), inputBuffer = NULL;
return (NULL);
}
currentToken = strtok(inputBuffer, " \t\n");
while (currentToken)
{
tokens[i] = _strdup(currentToken);
currentToken = strtok(NULL, " \t\n");
i++;
}
free(inputBuffer), inputBuffer = NULL;
tokens[i] = NULL;
return (tokens);
}
