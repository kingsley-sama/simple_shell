#include "shell.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * print_str - prints string to the terminal
 * Return: Void
 */
void print_str(char *str)
{
	unsigned int i;
	while (str[i] != 0)
	{
		i++;
	}
	write(STDOUT_FILENO, str, i);

}
