#include "minishell.h"

/**
 * main - Entry point for the minishell program
 *
 * @argc: Number of arguments given to the program
 * @argv: Arguments list
 *
 * Return: Returns the value of the last executed command
 */
int main(int argc, char **argv)
{
    char *cmdline = NULL;
    char **cmdargs;
    char *name;
    char prompt[] = "(minishell) ";
    bool status = true;

)
    name = (argv && argv[0] != NULL) ? argv[0] : "minishell";


    while (status)
    {

        write(1, prompt, strlen(prompt));
        status = false;
    }

    // Exit the program
    return 0;
}

