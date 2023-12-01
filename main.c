#include "shell.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * main - HSH shell entry function
 *@argc: count of command line input
 *@argv: argument array for the program
 * Return: the exit status
 */


int main()
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
		}
		print_str(input);
		free(input);
	} while (1);
	
	return (0);
}
