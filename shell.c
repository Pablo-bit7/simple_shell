#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024

/**
* execute_command - Execute a command with its arguments.
* @args: An array of strings representing the command and its arguments.
*
* Return: 1 on success, 0 on failure.
*/
int execute_command(char **args)
{
    pid_t child_pid;
    int status;

    child_pid = fork();

    if (child_pid == -1)
    {
        perror("Fork error");
        return (0);
    }

    if (child_pid == 0)
    {
        execvp(args[0], args);
        perror("Command not found");
        exit(EXIT_FAILURE);
    }
    else
    {
        waitpid(child_pid, &status, 0);

        if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
            printf("Error: Command exited with status %d\n", WEXITSTATUS(status));
    }

    return (1);
}

int main(void)
{
    char input[MAX_INPUT_LENGTH];
    char *args[MAX_INPUT_LENGTH];
    char *token;
    int i = 0;

    while (1)
    {
        printf("($) ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("\n");
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        token = strtok(input, " ");

        while (token != NULL)
        {
            args[i++] = token;
            token = strtok(NULL, " ");
        }

        args[i] = NULL;

        if (!execute_command(args))
            printf("Error: Failed to execute command\n");
    }

    return (0);
}
