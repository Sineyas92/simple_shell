#include "main.h"

/**
 * my_strtok - extract tokens from a buffer.
 * @line: input buffer.
 *
 * Return: tokens.
 */

char **my_strtok(char *line)
{
	char *token, **cmd, *temp;
	int count, i;

	cmd = NULL;
	token = NULL;
	count = 0;
	i = 0;
	temp = NULL;
	if (!line)
		return (NULL);
	temp = _strdup(line);
	token = strtok(temp, " \t\n");
	if (token == NULL)
	{
		free(line), line = NULL;
		free(temp), temp = NULL;
		return (NULL);
	}
	while (token)
	{
		count++;
		token = strtok(NULL, " \t\n");
	}
	free(temp), temp = NULL;
	cmd = malloc(sizeof(char *) * (count + 1));
	if (!cmd)
	{
		free(line), line = NULL;
		return (NULL);
	}
	token = strtok(line, " \t\n");
	while (token)
	{
		cmd[i] = _strdup(token);
		token = strtok(NULL, " \t\n");
		i++;
	}
	free(line), line = NULL;
	cmd[i] = NULL;
	return (cmd);
}
