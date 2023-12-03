#include "shell.h"
#include <string.h>
#include <stdio.h>

/**
 * string_tok- A function that parses a string of array
 * @str:The array of string.
 * @d: The delimiter of the string.
 * Return: void.
 */

void string_tok(char *str, const char *d)
{
	char *s;
	char *delimeter = " ";

	while (strtok(str,delimeter) != NULL)
	{
		s = strtok(s, delimeter);
	}
}
