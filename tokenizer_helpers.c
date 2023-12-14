#include "shell.h"

/**
 * is_delim - Func checks if a character is a delimiter
 * @c: The character to be checked
 * @delim: The array of delimiter characters
 * Return: 1 if it is a delimiter, 0 if it is not
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);

	return (0);
}
