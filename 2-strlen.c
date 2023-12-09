#include "shell.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * str_len - calculates the length of its integer input
 * @s: source string
 *
 * Return: strlen
 */
int str_len(char *s)
{
	int i;

	for (i = 0; *(s + i) != '\0'; i++)
		;
	return (i);
}
