#include "shell.h"

/**
 * get_line - gets the next line of input from stdin.
 * Return: character.
*/
char *get_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	if (isatty(STDIN_FILENO))
	write(STDOUT_FILENO, "$ ", 2);
	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/**
 * execute - Execute a command with arguments.
 * @array: array.
 * @argv: argument.
 * Return: The exit status
*/
int execute(char **array, char **argv)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execve(array[0], array, NULL) == -1)
		{
			perror(argv[0]);
			free_str(array);
			exit(0);
		}
	}
	else
	{
		wait(&status);
		free_str(array);
	}
	return (WEXITSTATUS(status));
}

