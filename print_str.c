#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
/**
 * print_str - prints string to the terminal
 * Return: Void
 */
void print_str(char *str)
{
	unsigned int i = 0;

	while (str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
	write(STDOUT_FILENO, str, i);

}
