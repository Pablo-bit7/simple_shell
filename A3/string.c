#include "main.h"

/**
* _strlen - Just returns the length of a string
* @s: String
* Return: The length of string
*/
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
* _strcmp - This does lexicogarphic comparison of two strangs.
* @s1: 1st string
* @s2: 2nd strang
* Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
*/
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
* starts_with - This function checks if needle starts with haystack
* @haystack: The string to search
* @needle: substring to find
* Return: The address of next char of haystack or NULL
*/
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
* _strcat - This just concatenates two strings
* @dest: Destination buffer
* @src: OG buffer
* Return: A pointer to the destination buffer
*/
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
