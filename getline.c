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
 * @argv: argument
 * @buf: integer.
 * Return: The exit status
*/
int execute(char **array, char **argv, int buf)
{
	pid_t pid;
	int status;
	char *num;

	num = _path(array[0]);
	if (!num)
	{
		p_err(argv[0], array[0], buf);
		free_str(array);
			return (0);
	}
	pid = fork();

	if (pid == 0)
	{
		if (execve(num, array, NULL) == -1)
		{
			free(num), num = NULL;
			free_str(array);
		}
	}
	else
	{
		wait(&status);
		free_str(array);
		free(num), num = NULL;
	}
	return (WEXITSTATUS(status));
}

