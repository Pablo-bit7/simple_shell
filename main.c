#include "shell.h"

/**
 * main - Entry point for the custom shell program.
 *
 * Description:
 * This function initializes the custom shell, reads user input in a loop,
 * tokenizes the input, and executes the corresponding commands.
 * The shell supports built-in commands such as 'exit' and 'env'.
 * It provides a prompt to the user, handles command line arguments,
 * and ensures proper memory management.
 *
 * Return:
 * The function returns 0 upon successful execution.
 */
int main(void)
{
	char *input_result;
	char **tokenized_command;
	size_t buffer_size = 120;

	while (1)
	{
		_prompt();
		input_result = read_input(&buffer_size);

		if (_strcmp(input_result, "exit") == 0 || _atoi(input_result) == EOF)
		{
			_printf("\n");
			free(input_result);  /* Free the allocated memory */
			break;
		}

		if (input_result[0] == '\0')  /* Empty string */
		{
			_printf("\n");
			free(input_result);
		}

		if (input_result[0] != '\0')
		{
			tokenized_command = tokenize(input_result, " ");
			execute_command(tokenized_command); /* Execute the command */
			/* Free allocated memory */
			free(tokenized_command);
			free(input_result);
		}
	}

	return (0);
}
