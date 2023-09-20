#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024

/**
* main - Entry point for the simple shell program.
*
* Return: Always 0.
*/
int main(void) {
    char input[MAX_INPUT_LENGTH];

    while (1) {
        /* Display a prompt */
        printf("($) ");
        fflush(stdout);

        /* Read user input */
        if (fgets(input, sizeof(input), stdin) == NULL) {
            /* Handle end of file (Ctrl+D) */
            printf("\n");
            break;
        }

        /* Remove newline character from input */
        input[strcspn(input, "\n")] = '\0';

        /* Try to execute the command */
        if (access(input, X_OK) == 0) {
            /* The command is executable */
            pid_t child_pid = fork();

            if (child_pid == -1) {
                perror("Fork error");
                return (1);
            }

            if (child_pid == 0) {
                /* Child process */
                execlp(input, input, NULL);

                /* If execlp returns, an error occurred */
                perror("Command execution error");
                exit(EXIT_FAILURE);
            } else {
                /* Parent process */
                int status;
                wait(&status);

                if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
                    printf("Error: Command exited with status %d\n", WEXITSTATUS(status));
                }
            }
        } else {
            /* The command is not executable */
            printf("./shell: No such file or directory\n");
        }
    }

    return (0);
}
