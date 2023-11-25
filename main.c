#include "shell.h"

/**
 * main - principal function
 * @ac: arguments
 * @argv: arguments
 * Return: 0
*/
int main(int ac, char **argv)
{
	char *line = NULL;
	size_t buf = 0;
	ssize_t n;
	char *token, **array;
	int  i = 0;
	(void) ac;
	(void) argv;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		write(1, "$", 2);
		n = getline(&line, &buf, stdin);
		array = malloc(sizeof(char *) * 1024);
		if (n == -1)
		{
			write(1, "\n", 2);
			break;
		}
		token = strtok(line, KO_DELIM);
		while (token != NULL)
		{
			array[i] = token;
			token = strtok(NULL, KO_DELIM);
			i++;
		}
		array[i] = NULL;
		free(array);
		execute(line, argv);
		i = 0;
		line = NULL;
	}
	return (0);
}
