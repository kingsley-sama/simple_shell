#include "shell.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * str_len - calculates the length of it’s integer input
 * @s: The source string.
 *
 * Return:The string length.
 */

int str_len(const char *s)
{
	int i;

	for (i = 0; *(s + i) != '\0'; i++)
	;

	return (i);
}
