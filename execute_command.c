#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "simple_shell.h"

/**
 * execute_command - Execute a command.
 *
 * This function executes a given command if it is an executable file.
 *
 * @command: The command to execute.
 */

void execute_command(const char *command)
{
	if (access(command, X_OK) == 0)
	{
		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(1);
		}
		if (pid == 0)
		{
			char **args = malloc(sizeof(char *) * 2);

			if (args == NULL)
			{
				perror("malloc");
				exit(1);
			}

			args[0] = strdup(command);
			args[1] = NULL;

			execve(command, args, NULL);
			perror("execve");

			free(args[0]);
			free(args);
			exit(1);
		}
		else
		{
			int status;

			wait(&status);
		}
	}
	else
	{
		printf("%s: No such file or directory\n", command);
	}
}

