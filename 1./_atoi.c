#include "main.h"

/**
 * is_delim - checks if a character is a delimiter
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

/**
 * interactive - Checks if the shell is running in interactive mode
 * @info: A pointer to a structure holding relevant information
 *
 * Return: 1 if the shell is in interactive mode, 0 otherwise
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * _atoi - Converts a string to an integer
 * @s: The input string to be converted
 *
 * Return: The converted integer if valid, 0 if no numbers are found in the str
 */

int _atoi(char *s)
{
	int index, sign = 1, state = 0, value;
	unsigned int num = 0;

	for (index = 0; s[index] != '\0' && state != 2; index++)
	{
		if (s[index] == '-')
			sign *= -1;

		if (s[index] >= '0' && s[index] <= '9')
		{
			state = 1;
			num *= 10;
			num += (s[index] - '0');
		}
		else if (state == 1)
			state = 2;
	}

	if (sign == -1)
		value = -num;
	else
		value = num;

	return (value);
}

/**
 * _isalpha - Checks if a character is an alphabetic character
 * @c: The ASCII value of the character
 *
 * Return: 1 if the character is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

