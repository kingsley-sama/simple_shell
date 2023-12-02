#include "shell.c"
#include <string.h>
#include <stdio.h>

/**
 * string_tok- A function that parses a string of array
 * @str:The array of string.
 * @d: The delimiter of the string.
 *
 * Return: void.
 */

void string_tok(char *str, const char *d)
{
	str[] = "This is simple shell";
	d[] = " ";

	*str_parse = strtok(str, d);

	while (str_parse != NULL)
	{
	_putchar("%s\n", str_parse);
	str_parse = strtok(NULL, d);
	}
}
