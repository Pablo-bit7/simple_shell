#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "simple_shell.h"

extern char **environ;

/**
 * print_environment - Print the environment variables.
 *
 * This function prints the environment variables to the standard output, one
 * per line.
 */

void print_environment(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}

