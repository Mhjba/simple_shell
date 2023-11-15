#include "shell.h"

/**
 * main - principal function
 * @ac: argument
 * @av: array of arguments
 * Return: 0
*/
int main(int ac, char **av)
{
	char *line;
	size_t len;
	ssize_t cmd = 0;
	char *token, **array = NULL;
	int i = 0;
	(void) ac, (void) av;

	while (1)
		{
		if (isatty(STDIN_FILENO))
		write(STDIN_FILENO, "$ ", 2);
		cmd = getline(&line, &len, stdin);
		if (cmd == -1)
		{
			break;
		}
		token = strtok(line, " \t\n");
		array = malloc(sizeof(char *) * 1024);
		while (token != NULL)
		{
			array[i] = token;
			token = strtok(NULL, " \t\n");
			i++;
		}
		array[i] = NULL;
		execute(line, array);
	}
		free(line);
		return (0);
}
