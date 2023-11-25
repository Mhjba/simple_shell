#include "shell.h"

/**
 * execute - execute the command
 * @line: ponter to string
 * @argv: array of pointers
 *
 * Return: int.
 */

int execute(char *line, char **argv)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(line, argv, environ) == -1)
		{
			perror(argv[0]);
			free(line);
			exit(0);
		}
	}
	else
	{
		wait(&status);
		free(line);
	}
		return (WEXITSTATUS(status));
}
