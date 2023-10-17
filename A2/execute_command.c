#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "simple_shell.h"
/**
 * execute_command - Execute a shell command in a child process.
 *
 * @command: A string with the command and arguments.
 *
 * This function forks a new process to execute the provided command and
 * checks for errors during the process creation and execution.
 *
 * Return: Always 1 (not indicative of command success).
 */

int execute_command(char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		char *args[32];
		int arg_count = 0;

		tokenize_command(command, args, &arg_count);

		if (execvp(args[0], args) == -1)
		{
			fprintf(stderr, "./shell: %s: not found\n", args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);

		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			fprintf(stderr, "./shell: %s: Exit status %d\n",
					command, WEXITSTATUS(status));
		}
	}

	return (1);
}

