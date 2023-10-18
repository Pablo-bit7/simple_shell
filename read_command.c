#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simple_shell.h"
/**
 * read_command - Read a command from the user.
 *
 * This function reads a command from the user and returns it as a string.
 *
 * Return: A pointer to the string containing the command.
 */

char *read_command()
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read;

	printf("#cisfun$ ");
	read = getline(&input, &len, stdin);

	if (read == -1)
	{
		if (feof(stdin))
		{
			free(input);
			exit(0);
		}
		else
		{
			perror("getline");
			free(input);
			exit(1);
		}
	}

	input[read - 1] = '\0';

	return (input);
}

