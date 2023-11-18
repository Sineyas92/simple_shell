#include "main.h"

/**
 * my_exec - executes a program.
 * @command: vector (or array of comand strings).
 * @arguments: argument vector.
 * Return: nothing.
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
