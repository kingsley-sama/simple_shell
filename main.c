#include "shell.h"
#include <stdio.h>
#include <unistd.h>
/**
 * main - HSH shell entry function
 *@argc: count of command line input
 *@argv: argument array for the program
 * Return: the exit status
 */


int main()
{
	char s[10];
	do {
		char command[20];
		unsigned int  inputlen = 0;
		read(STDIN_FILENO, command, inputlen);
		
		print_str("($)");						\
		putchar('\n');
	} while (1 && !EOF);
	return (0);
}
