#include "main.h"

/**
 * myExecute - exécute un programme.
 * @command: vecteur (ou tableau de chaînes de commandes).
 * @arguments: vecteur d'arguments.
 * Return: rien.
 */
int my_exec(char **command, char **arguments)
{
    pid_t child_pid;
    int child_status;

    child_pid = fork();
    if (child_pid == 0)
    {
        if (execve(command[0], command, environ) == -1)
        {
            perror(arguments[0]);
            free2d(command);
            exit(0);
        }
    }
    else
    {
        waitpid(child_pid, &child_status, 0);
        free2d(command);
    }

    return WEXITSTATUS(child_status);
}

