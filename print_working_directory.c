#include "shell.h"
#include <unistd.h>
#include <stdio.h>

/**
 * print_current_directory - prints the current working directory
 * Return: 0 on succes
 */

int print_current_directory(void)
{
	char cwd[1024];

	getcwd(cwd, sizeof(cwd));
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		print_str(cwd);
		return (0);
	}
	return (-1);
}
