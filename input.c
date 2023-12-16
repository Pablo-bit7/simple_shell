#include "shell.h"

/**
 * read_input - Reads a line of input from the user.
 * @size: A pointer to the size of the buffer.
 *
 * Return: The string read, or NULL on failure.
 */
char *read_input(size_t *size)
{
	char *buffer = NULL;
	ssize_t n = getline(&buffer, size, stdin);

	if (n == -1)  /* Error or EOF */
	{
		free(buffer);
		return (NULL);
	}

	if (n > 0 && buffer[n - 1] == '\n')  /* Remove trailing newline */
		buffer[n - 1] = '\0';

	return (buffer);
}
