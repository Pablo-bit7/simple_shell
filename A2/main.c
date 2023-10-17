#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "simple_shell.h"

#define MAX_INPUT_LENGTH 1024

/**
 * main - Entry point of the simple shell program
 *
 * Description:
 * - This function sets up the main loop for the simple shell.
 * - It repeatedly prompts the user for input, processes commands,
 *   and either executes them or performs built-in actions.
 *
 * Return:
 * - 0 on successful program termination.
 */

int main(void)
{
	char input[MAX_INPUT_LENGTH];

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		input[strcspn(input, "\n")] = '\0';

		if (strcmp(input, "exit") == 0)
		{
			break;
		}
		else if (strcmp(input, "env") == 0)
		{
			print_environment();
		}
		else
		{
			execute_command(input);
		}
	}

	return (0);
}

