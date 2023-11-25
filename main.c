#include "shell.h"

/**
 * main - principal function
 * Return: 0
*/
int main(void)
{
	char *line = NULL;
	size_t buf = 0;
	ssize_t n;
	char *token, **array;
	int  i = 0;

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
		execute(line, array);
		i = 0;
		free(line);
		line = NULL;
	}
	return (0);
}
