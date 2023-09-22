#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 1024

/**
 * _strlen - Calculate the length of a string.
 * @str: The string to calculate the length of.
 *
 * Return: The length of the string (number of characters).
 */
size_t _strlen(const char *str)
{
    size_t length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return (length);
}

int main(int argc, char *argv[])
{
    char input[MAX_INPUT_LENGTH];
    int is_interactive = isatty(STDIN_FILENO); /* Check if standard input is a terminal */
    size_t input_length;

    if (argc == 1 || (argc == 2 && is_interactive))
    {
        /* Interactive mode: no arguments provided or single argument in interactive mode */
        while (1)
        {
            if (is_interactive)
            {
                write(STDOUT_FILENO, "($) ", 4);
            }

            if (fgets(input, sizeof(input), stdin) == NULL)
            {
                if (is_interactive)
                {
                    write(STDOUT_FILENO, "\n", 1);
                }
                break;
            }

            input_length = 0;
            while (input[input_length] != '\0' && input[input_length] != '\n')
            {
                input_length++;
            }
            input[input_length] = '\0';

            if (access(input, X_OK) == 0)
            {
                pid_t child_pid = fork();

                if (child_pid == -1)
                {
                    perror("Fork error");
                    return (1);
                }

                if (child_pid == 0)
                {
                    if (execve(input, argv, NULL) == -1)
                    {
                        perror("Command execution error");
                        _exit(EXIT_FAILURE);
                    }
                }
                else
                {
                    int status;
                    char status_char;

                    waitpid(child_pid, &status, 0);

                    if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
                    {
                        char err_msg[] = "Error: Command exited with status ";
                        write(STDOUT_FILENO, err_msg, _strlen(err_msg));

                        status_char = WEXITSTATUS(status) + '0';
                        write(STDOUT_FILENO, &status_char, 1);
                        write(STDOUT_FILENO, "\n", 1);
                    }
                }
            }
            else
            {
                write(STDOUT_FILENO, "./shell: No such file or directory\n", 36);
            }
        }
    }
    else if (argc == 2)
    {
        /* Non-interactive mode: one argument provided */
        if (access(argv[1], X_OK) == 0)
        {
            pid_t child_pid = fork();

            if (child_pid == -1)
            {
                perror("Fork error");
                return (1);
            }

            if (child_pid == 0)
            {
                if (execve(argv[1], argv, NULL) == -1)
                {
                    perror("Command execution error");
                    _exit(EXIT_FAILURE);
                }
            }
            else
            {
                int status;
                char status_char;

                waitpid(child_pid, &status, 0);

                if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
                {
                    char err_msg[] = "Error: Command exited with status ";
                    write(STDOUT_FILENO, err_msg, _strlen(err_msg));

                    status_char = WEXITSTATUS(status) + '0';
                    write(STDOUT_FILENO, &status_char, 1);
                    write(STDOUT_FILENO, "\n", 1);
                }
            }
        }
        else
        {
            write(STDOUT_FILENO, "./shell: No such file or directory\n", 36);
        }
    }
    else
    {
        write(STDOUT_FILENO, "Usage: ", 7);
        write(STDOUT_FILENO, argv[0], _strlen(argv[0]));
        write(STDOUT_FILENO, " [command]\n", 12);
        return (1);
    }

    return (0);
}
