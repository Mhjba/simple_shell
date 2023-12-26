#include "shell.h"

/**
 * splits - split a string into a double char pointer.
 * @str: string.
 * Return: array.
*/
char **splits(char *str)
{
	char *token = NULL, *tokens = NULL;
	char **array = NULL;
	int con = 0, i = 0;

	if (!str)
		return (NULL);
	tokens = _strdup(str);
	token = strtok(tokens, " \t\n");
	if (token == NULL)
	{
		free(str = NULL);
		free(tokens = NULL);
		return (NULL);
	}
	while (token)
	{
		con++;
		token = strtok(NULL, " \t\n");
	}
	free(tokens = NULL);
	array = malloc(sizeof(char *) * (con + 1));
	if (!array)
	{
		free(str);
		return (NULL);
	}
	token = strtok(str, " \t\n");
	while (token)
	{
		array[i] = _strdup(token);
		token = strtok(NULL, " \t\n");
		i++;
	}
	free(str = NULL);
	array[i] = NULL;
	return (array);
}
