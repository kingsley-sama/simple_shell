#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
/**
 * _putchar - writes a character to stdout
 * Return: Void
 */
int  _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

