#include "shell.h"

/**
 * _strlen - returns the length of string
 * @s: string.
 * Return: length.
*/
int _strlen(char *s)
{
	int len = 0;

	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}
/**
 * _strcat - concatenates to strings
 * @dest: destination.
 * @src: source.
 * Return: the pointer to dest
*/
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	return (dest);
}

/**
 * _strcmp - performs of tow strings.
 * @s1: the first string
 * @s2: the second string
 * Return: string
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i])
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (i);
}
