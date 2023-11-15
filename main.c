#include "minishell.h"

/**
 * main - entry point
 *
 * @argc: number of arguments given to the program
 * @argv: arguments list
 *
 * Return: returns the value of the last executed command
 */
int main(int argc, char **argv)
{
    char *cmdline = NULL;
    char **cmdargs;
    char prompt[] = "(hsh) ";
    Bool status = true;

    name = (argv[0] != NULL) ? argv[0] : NULL;

    write(1, prompt, strlen(prompt));
    cmdline = get_user_input();

    // Rest of the code goes here...

    return 0;
}

