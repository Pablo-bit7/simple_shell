#include "main.h"

/**
* _putsfd - Print a string to a specified file descriptor.
* @str: The input string
* @fd: The file descriptor
* Return: The number of characters printed
*/
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}

/**
* _putfd - Write a character to a specified file descriptor.
* @c: The character to write
* @fd: The file descriptor
* Return: On success 1, -1 if else
*/
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
* _eputs - Print input string
* @str: The string to print
* Return: None (void)
*/
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
* _eputchar - Write a character to stderr.
* @c: The character to write to stderr
* Return: 1 if success, -1 if else
* (errno set appropriately)
*/
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

