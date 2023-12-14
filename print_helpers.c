#include "shell.h"

/**
 * _print_str - prints a string
 * @str: The string to print
 *
 * Return: Number of characters printed
 */
int _print_str(char *str)
{
	int count;

	if (str == NULL)
		str = "(null)";
	count = 0;
	while (*str != '\0')
	{
		count += _putchar(*str);
		str++;
	}
	return (count);
}

/**
 * _print_int - prints an integer
 * @n: The integer to print
 *
 * Return: Number of characters printed
 */
int _print_int(int n)
{
	int count;

	count = 0;
	if (n < 0)
	{
		count += _putchar('-');
		n = -n;
	}
	count += _print_uint((unsigned int)n);
	return (count);
}

/**
 * _print_uint - prints an unsigned integer
 * @n: The unsigned integer to print
 *
 * Return: Number of characters printed
 */
int _print_uint(unsigned int n)
{
	int count;

	count = 0;
	if (n >= 10)
		count += _print_uint(n / 10);
	count += _putchar((n % 10) + '0');
	return (count);
}

/**
 * _print_oct - prints an octal number
 * @n: The unsigned integer to print in octal
 *
 * Return: Number of characters printed
 */
int _print_oct(unsigned int n)
{
	int count;

	count = 0;
	if (n >= 8)
		count += _print_oct(n / 8);
	count += _putchar((n % 8) + '0');
	return (count);
}

/**
 * _print_ptr - prints a pointer address in hexadecimal
 * @ptr: The pointer to print
 *
 * Return: Number of characters printed
 */
int _print_ptr(void *ptr)
{
	int count;

	count = 0;
	count += _putchar('0');
	count += _putchar('x');
	count += _print_hex((unsigned long)ptr, 1);
	return (count);
}
