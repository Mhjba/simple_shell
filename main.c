#include "shell.h"

/**
 * free_str - frees th string.
 * @argv: arguments.
 * Return: void.
*/
void free_str(char **argv)
{
	int i;

	if (!argv)
		return;
	for (i = 0; argv[i]; i++)
	{
		free(argv[i]);
		argv[i] = NULL;
	}
	free(argv), argv = NULL;
}

/**
 * main - simple shell main function.
 * @ac: arguments.
 * @av: arguments.
 * Return: no return.
*/

int main(int ac, char **av)
{
	char *line = NULL;
	char **buffer = NULL;
	int status = 0;
	(void) ac;

	while (1)
	{
	line = get_line();
	if (line == NULL)
	{
		if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
			return (status);
	}
		buffer = splits(line);
		if (!buffer)
			continue;
		status = execute(buffer, av);
	}
}

