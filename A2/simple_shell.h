#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

void print_environment(void);
int execute_command(char *command);
void tokenize_command(char *command, char *args[], int *arg_count);

#endif
