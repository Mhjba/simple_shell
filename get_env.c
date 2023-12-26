#include "shell.h"

/**
 * _getenv - Get the value of an environment variable
 * @var: Name of the environment variable
 * Return: null.
 */
char *_getenv(char *var)
{
	char *buffer, *key;
	char *value, *var_env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		buffer = _strdup(environ[i]);
		key = strtok(buffer, "=");
		if (_strcmp(key, var) == 0)
		{
			value = strtok(NULL, "\n");
			var_env = _strdup(value);
			free(buffer);
			return (var_env);
		}
		free(buffer), buffer = NULL;
	}
	return (NULL);
}

/**
 * rev_str - reverses a string by taking two parameters.
 * @str: pointer to the beginning of a character array
 * @len: parameter holds the length of the string.
 * Return: void.
*/
void rev_str(char *str, int len)
{
	char tmp;
	int start = 0;
	int i = len - 1;

	while (start < i)
	{
		tmp = str[start];
		str[start] = str[i];
		str[i] = tmp;
		start++;
		i--;
	}
}
