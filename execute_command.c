#include "shell.h"

/**
 * execute_command - Executes the given command.
 * @command: An array of strings representing the command and its arguments.
 */
void execute_command(char **command)
{
	extern char **environ;

	if (command == NULL || command[0] == NULL)
	{
		/* No command entered or empty command */
		return;
	}

	/* Check for built-in commands */
	if (_strcmp(command[0], "env") == 0)
	{
		/* Handle env command */
		print_environment();
	}
	else
	{
	/* Not a built-in command, attempt to execute */
		if (access(command[0], X_OK) == 0)
		{
			/* The command is executable, execute it */
			int status = execute_external_command(command, environ);

			if (status == -1)
			{
				/* Error executing the command */
				perror("Error executing command");
			}
		}
		else
		{
			/* Command not found in PATH */
			_printf("./shell: No such file or directory: %s\n", command[0]);
		}
	}
}
