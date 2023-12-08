#include "shell.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * main - HSH entry point.
 * @argc: Number of command line argument.
 *@argv: Argument vector.
 * Return: Exit status.
 */
int main(void)
{
	do {
		char *input = NULL;
		ssize_t getline_val;
		size_t input_size = 0;

		print_str("($)");
		getline_val = getline(&input, &input_size, stdin);
		if (getline_val == -1)
		{
			perror("getline error");
			free(input);
		}
		print_str(input);
		print_current_directory();
		free(input);
		putchar('\n');
	} while (1);
	return (0);
}
