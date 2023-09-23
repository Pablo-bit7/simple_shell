#include "main.h"

/**
* _memset - This just fills memory with a constant byte
* @s: Pointer to memory
* @b: Byte to fill with
* @n: Num of bytes to be filled
* Return: (s), the pointer to the memory area
*/
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
* ffree - This function just frees a string of strings
* @pp: String of strings
*/
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
* _realloc - Reallocates a block of memory
* @ptr: The pointer to previous malloc'ated block
* @old_size: byte size of the previous block
* @new_size: byte size of the new block
* Return: A pointer to the ol'block
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
