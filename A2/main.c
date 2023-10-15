#include <stdio.h>
#include <string.h>
#include "simple_shell.h"

#define MAX_INPUT_LENGTH 1024

/**
* main - Entry point to the shell program.
*
* Return: 0
*
* Description: Contains the shell program's main `while` loop.
*              Displays the prompt, handles EOF and commands.
*/
int main(void)
{
	char input[MAX_INPUT_LENGTH];

	while (1)
	{
		printf("#cisfun$ ");  /* Display the prompt */
		fflush(stdout);

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			/* Handle Ctrl+D (end of file) */
			printf("\n");
			break;
		}

		/* Remove the trailing newline character */
		input[strcspn(input, "\n")] = '\0';

		/* Execute the command */
		execute_command(input);
	}

	return (0);
}
