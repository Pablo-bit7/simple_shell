#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

void print_environment(void);
void execute_command(const char *command);
void tokenize_command(char *command, char *args[], int *arg_count);
char *read_command();

#endif