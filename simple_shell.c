#include "main.h"

/**
 * main - Simple shell.
 * @argc: arguments count.
 * @argv: arguments vector.
 *
 * Return: Nothing.
 */
int main(int argc, char **argv)
{
    int status = 0, j;
    char **tokens = NULL, *inputLine = NULL;
    (void)argc; // Ignorer l'avertissement "unused parameter"

    while (1)
    {
        inputLine = my_getline();
        if (inputLine == NULL)
        {
            if (isatty(STDIN_FILENO))
                write(1, "\n", 1);
            return status;
        }

        tokens = my_strtok(inputLine);
        if (!tokens)
            continue;

        if (_strcmp(tokens[0], "exit") == 0)
        {
            if (tokens[1] != NULL)
            {
                status = _atoi(tokens[1]);
                if (status == -1)
                    exit(status);
            }
            free2d(tokens);
            return status;
        }
        else if (_strcmp(tokens[0], "env") == 0)
        {
            for (j = 0; environ[j]; j++)
            {
                write(1, environ[j], _strlen(environ[j]));
                write(1, "\n", 1);
            }
            free2d(tokens);
            return status;
        }
        status = my_exec(tokens, argv);
    }
}

