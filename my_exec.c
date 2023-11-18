#include "main.h"

/**
 * my_exec - executes a program.
 * @cmd: vector (or array of comand strings).
 * @argv: argument vector.
 * Return: nothing.
 */

int my_exec(char **cmd, char **argv)
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror(argv[0]);
			free2d(cmd);
			exit(0);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free2d(cmd);
	}
	return (WEXITSTATUS(status));
}
