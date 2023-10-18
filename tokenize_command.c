#include <string.h>
#include "simple_shell.h"
/**
 * tokenize_command - Split a shell command into individual arguments.
 *
 * @command: The input shell command string to be tokenized.
 * @args: An array to store the resulting arguments.
 * @arg_count: A pointer to an integer to track the number of arguments.
 */

void tokenize_command(char *command, char *args[], int *arg_count)
{
	char *token = strtok(command, " ");

	while (token != NULL)
	{
		args[(*arg_count)++] = token;
		token = strtok(NULL, " ");
	}

	args[*arg_count] = NULL;
}

