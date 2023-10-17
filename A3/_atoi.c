#include "main.h"

/**
* is_delim - checks for the delimeter char
* @c: Holds the character to asses
* @delim: Holds the delimeter string array
* Return: 1 if true, 0 if not
*/
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
* interactive - Determines if shell is in interactive mode
* @info: This jsut holds struct address
*
* Return: 1 if interactive, 0 otherwise
*/
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
* _atoi - This function converts a string to an integer
* @s: Holds the string to be converted
* Return: 0 if no numbers in string, converted number otherwise
*/
int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

/**
* _isalpha - checks is a char is in the alphabet
* @c: Holds ASCII value of char
* Return: 1 if in alphabet, 0 otherwise
*/
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
