#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
/**
 * _putchar - Writes single character to stdout.
 * @c: The character to write.
 * Return: Void
 */
int  _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

