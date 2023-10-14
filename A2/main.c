#include <stdio.h>
#include "simple_shell.h"

#define MAX_INPUT_LENGTH 1024

int main(void) {
    char input[MAX_INPUT_LENGTH];

    while (1) {
        printf("#cisfun$ ");  // Display the prompt
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL) {
            // Handle Ctrl+D (end of file)
            printf("\n");
            break;
        }

        // Remove the trailing newline character
        input[strcspn(input, "\n")] = '\0';

        // Execute the command
        execute_command(input);
    }

    return 0;
}