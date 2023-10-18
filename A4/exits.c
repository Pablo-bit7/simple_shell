#include "main.h"

/**
* *_strncat - Concatenate two strings up to a maximum number of bytes.
* @dest: The first string
* @src: The second string
* @n: The maximum number of bytes to be used
* Return: the concatenated string
*/
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
* *_strchr - Find a character in a string.
* @s: The string to be parsed
* @c: The character to look for
* Return: A pointer to the memory area (s) where the character is found
*/
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

/**
* *_strncpy - Copy a string up to a specified number of characters.
* @dest: Destination string to be copied to
* @src: Original string
* @n: Number of characters to be copied
* Return: The concatenated string
*/
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

