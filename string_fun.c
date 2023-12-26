#include "shell.h"

/**
 * _strlen - custom function to get the length of a string
 * @str: pointer to the string.
 * Return: the length of a string
 */
int _strlen(char *str)
{
	int len = 0;

	while (*(str + len))
	{
		len++;
	}
	return (len);
}
/**
 * _strcat - concatenate two strings.
 * @dest: the destination.
 * @src: the source.
 *
 * Return: character.
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
 * _strcpy - copies a string.
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer .
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
/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer.
 */
char *_strdup(char *str)
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
 * _strcmp - compares string 1 with string 2
 * @s1: first string
 * @s2: second string
 * Return: 0.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0')
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (0);
}
