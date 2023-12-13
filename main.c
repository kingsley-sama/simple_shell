#include "shell.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/**
 * main - HSH entry point.
 * @argc: Number of command line argument.
 *@argv: Argument vector.
 * Return: Exit status.
 */
int main(int argc, char *argv[])
{
	int is_interactive = isatty(STDIN_FILENO);
	char *input = NULL;
	char *exit_call = "exit";
	ssize_t getline_val;
	size_t input_size = 0;

	do
	{
		if (is_interactive)
		{
			print_str("($)");
		}
		getline_val = getline(&input, &input_size, stdin);
		if (getline_val == -1 || strcmp(input, exit_call) == 0) {
			if (is_interactive) {
				if (getline_val == -1)
					putchar('\n');
				
			}
			break;
		}
		if (strlen(input) > 0 && input[strlen(input) - 1] == '\n')
			input[strlen(input) - 1] = '\0';
		call_command(input);
		free(input);
		if (is_interactive)
			putchar('\n');
	} while (is_interactive);
	return 0;
}
