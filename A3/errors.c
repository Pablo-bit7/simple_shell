#include "main.h"

/**
* _putsfd - Also prints an input string
* @str: The string
* @fd: Holds the file descriptor
* Return: Num of chars put
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
* _putfd - This writes character to given fd
* @c: Holds character
* @fd: Holds file descriptor
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
* _eputs - Just prints input string
* @str: Holds the string
* Return: Nothing
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
* _eputchar - Writes to stderr
* @c: Holds the character
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
