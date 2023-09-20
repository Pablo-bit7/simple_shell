#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024

/**
 * main - Entry point of the shell program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the arguments.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[]) {
    char input[MAX_INPUT_LENGTH];
    int is_interactive = isatty(STDIN_FILENO);  /* Check if standard input is a terminal */

    if (argc == 1 || (argc == 2 && is_interactive)) {
        /* Interactive mode: no arguments provided or single argument in interactive mode */
        while (1) {
            if (is_interactive) {
                printf("($) ");
                fflush(stdout);
            }

            if (fgets(input, sizeof(input), stdin) == NULL) {
                if (is_interactive) {
                    printf("\n");
                }
                break;
            }

            input[strcspn(input, "\n")] = '\0';

            if (access(input, X_OK) == 0) {
                pid_t child_pid = fork();

                if (child_pid == -1) {
                    perror("Fork error");
                    return (1);
                }

                if (child_pid == 0) {
                    execlp(input, input, NULL);
                    perror("Command execution error");
                    exit(EXIT_FAILURE);
                } else {
                    int status;
                    wait(&status);

                    if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
                        printf("Error: Command exited with status %d\n", WEXITSTATUS(status));
                    }
                }
            } else {
                printf("./shell: No such file or directory\n");
            }
        }
    } else if (argc == 2) {
        /* Non-interactive mode: one argument provided */
        if (access(argv[1], X_OK) == 0) {
            pid_t child_pid = fork();

            if (child_pid == -1) {
                perror("Fork error");
                return (1);
            }

            if (child_pid == 0) {
                execlp(argv[1], argv[1], NULL);
                perror("Command execution error");
                exit(EXIT_FAILURE);
            } else {
                int status;
                wait(&status);

                if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
                    printf("Error: Command exited with status %d\n", WEXITSTATUS(status));
                }
            }
        } else {
            printf("./shell: No such file or directory\n");
        }
    } else {
        printf("Usage: %s [command]\n", argv[0]);
        return (1);
    }

    return (0);
}
