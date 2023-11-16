#include "shell.h"

/**
 * execute - execute the command
 * @line: ponter to string
 * @array: array of pointers
 *
 * Return: 0.
 */

void execute(char *line, char **array)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(line, array, NULL))
		{
			perror("error");
			exit(1);
		}
	}
	else
	{
		wait(&status);
		free(array);
	}
		return;
}
