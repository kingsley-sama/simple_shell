#include "shell.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _strlen - swaps the value of two integer
 * Return: i the length of the string
 *@s: this is the character whose length is to be determined
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; *(s + i) != '\0'; i++)
		;
	return (i);
}
