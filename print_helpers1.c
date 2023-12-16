#include "shell.h"

/**
 * _print_hex - prints a number in hexadecimal
 * @n: The unsigned integer to print in hexadecimal
 * @uppercase: Flag indicating whether to use uppercase letters
 *
 * Return: Number of characters printed
 */
int _print_hex(unsigned int n, int uppercase)
{
	int count;

	count = 0;
	if (n >= 16)
		count += _print_hex(n / 16, uppercase);
	if (n % 16 < 10)
		count += _putchar((n % 16) + '0');
	else
		count += _putchar((n % 16) - 10 + (uppercase ? 'A' : 'a'));
	return (count);
}

/**
 * _print_rev_str - prints a reversed string
 * @str: The string to print in reverse
 *
 * Return: Number of characters printed
 */
int _print_rev_str(char *str)
{
	int count, len, i;

	count = 0;
	if (str != NULL)
	{
		len = 0;
		while (str[len] != '\0')
			len++;
		for (i = len - 1; i >= 0; i--)
			count += _putchar(str[i]);
	}
	return (count);
}

/**
 * _putchar - Writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
