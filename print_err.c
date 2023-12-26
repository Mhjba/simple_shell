#include "shell.h"

/**
 * p_err - prints an error message
 * @len:  pointer to a character array
 * @buf: pointer to a character array
 * @d: integer
 * Return: void.
 */

void p_err(char *len, char *buf, int d)
{
	char *idx, mssg[] = ": not found\n";

	idx = _atoi(d);
	write(STDERR_FILENO, len, _strlen(len));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, _strlen(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, buf, _strlen(buf));
	write(STDERR_FILENO, mssg, _strlen(mssg));

	free(idx);
}


/**
 *_atoi - converts a string to an integer
 *@buf: the string to be converted
 *Return: character.
 */
char *_atoi(int buf)
{
	char output[20];
	unsigned int i = 0;

	if (buf == 0)
		output[i++] = '0';
	else
	{
		while (buf > 0)
		{
			output[i++] = (buf % 10) + '0';
			buf /= 10;
		}
	}
	output[i] = '\0';
	rev_str(output, i);
	return (_strdup(output));
}
