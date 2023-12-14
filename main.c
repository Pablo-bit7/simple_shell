#include "shell.h"

int main(void)
{
    char **tokenized_command;
    char *input_result;

    while (1)
    {
        _prompt();
        input_result = read_input();

        if (input_result == EOF || strcmp(input_result, "exit") == 0)
        {
            printf("\n");
            break;
        }

        if (input_result != NULL)
            tokenized_command = tokenize(command, " ");

        /* Execute the command (You need to implement this function) */
        execute_command(tokenized_command);
    }

    return (0);
}
