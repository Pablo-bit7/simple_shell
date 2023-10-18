#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "simple_shell.h"
/**
 * main - Entry point of the program.
 *
 * This function is the entry point of the program.
 * It contains the main logic for the shell.
 *
 * Return: Always 0.
 */

int main(void)
{
	char *command;

	while (1)
	{
		command = read_command();
		execute_command(command);
		free(command);
	}

	return (0);
}

