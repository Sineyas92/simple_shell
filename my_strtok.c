#include "main.h"
/**
 * my_strtok - extract tokens from a buffer.
 * @inputBuffer: input buffer.
 *
 * Return: currentTokens.
 */
char **my_strtok(char *inputBuffer)
{
char *currentToken, **tokens, *tempBuffer;
int tokenCount, index;

tokens = NULL;
currentToken = NULL;
tokenCount = 0;
index = 0;
tempBuffer = NULL;
if (!inputBuffer)
return NULL;

tempBuffer = _strdup(inputBuffer);
currentToken = strtok(tempBuffer, " \t\n");

if (currentToken == NULL)
{
free(inputBuffer), inputBuffer = NULL;
free(tempBuffer), tempBuffer = NULL;
return NULL;
}

while (currentToken)
{
tokenCount++;
currentToken = strtok(NULL, " \t\n");
}
free(tempBuffer), tempBuffer = NULL;
tokens = malloc(sizeof(char *) * (tokenCount + 1));

if (!tokens)
{
free(inputBuffer), inputBuffer = NULL;
return NULL;
}
currentToken = strtok(inputBuffer, " \t\n");

while (currentToken)
{
tokens[index] = _strdup(currentToken);
currentToken = strtok(NULL, " \t\n");
index++;
}
free(inputBuffer), inputBuffer = NULL;
tokens[index] = NULL;
return (tokens);
}

