#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
* execute_command - Attempts to execute a command from input.
* @command: A pointer to the command.
*
* Return: 1
*
* Description: Parses the input as a command, else error.
*              Creates a child process, else error.
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
		/* In the child process, execute the command */
		if (execlp(command, command, NULL) == -1)
		{
			/* If execlp returns, the command execution failed */
			perror(command);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* In the parent process, wait for the child to complete */
		int status;

		waitpid(pid, &status, 0);

		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			fprintf(stderr, "./shell: %s: Exit status %d\n", command, WEXITSTATUS(status));
	}

	return (1);
}
