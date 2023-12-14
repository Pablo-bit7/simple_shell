#include "shell.h"

/**
 * read_input - Reads a line of input from the user.
 * @buffer: The buffer to store the input.
 * @size: The size of the buffer.
 * 
 * Return: The number of characters read.
 */
ssize_t read_input(char *buffer, size_t size)
{
    ssize_t n = getline(&buffer, &size, stdin);

    return (n);
}
