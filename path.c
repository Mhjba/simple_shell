#include "shell.h"

/**
 * _path - handle the path function.
 * @path: commands.
 * Return: null.
 */
char *_path(char *path)
{
	char *path_env, *full, *cmp;
	int i;
	struct stat st;

	for (i = 0; path[i]; i++)
	{
		if (path[i] == '/')
		{
			if (stat(path, &st) == 0)
			{
				return (_strdup(path));
			}
			return (NULL);
		}
	}
	path_env = _getenv("PATH");
	if (!path_env)
	{
		return (NULL);
	}
	cmp = strtok(path_env, ":");
	while (cmp != NULL)
	{
		full = malloc(_strlen(cmp) + _strlen(path) + 2);
		if (full)
		{
			_strcpy(full, cmp);
			_strcat(full, "/");
			_strcat(full, path);
			if (stat(full, &st) == 0)
			{
				free(path_env);
				return (full);
			}
			free(full);
		}
		cmp = strtok(NULL, ":");
	}
	free(path_env);
	return (NULL);
}
