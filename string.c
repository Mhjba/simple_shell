#include "shell.h"

/**
 * _strdup - dupilicates a string
 * @str: the string to duplicate
 * Return: pointer
*/

char *_strdup(const char *str)
{
	char *ptr;
	int i, len = 0;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		len++;
		str++;
	}
	str = str - len;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		ptr[i] = str[i];
	return (ptr);
}

/**
 * _strcmp - compis a string
 * @s1: string
 * @s2: string
 *
 * Return: ineger
*/
int _strcmp(char *s1, char *s2)
{
	int cmp;

	cmp = (int)*s1 - (int)*s2;
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
		cmp = (int) *s1 - (int) *s2;
	}
	return (cmp);
}

/**
 * _strlen - lenis a string
 * @str: string
 *
 * Return: integer
*/
int _strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}

/**
 * _strcat - cates a string
 * @dest: the destination
 * @src: the source
 *
 * Return: character
*/
char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*p)
		p++;

	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}
	*p = *src;
	return (dest);
}

/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
*/
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

