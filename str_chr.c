#include "shell.h"
#include <stdio.h>

/**
 * _strchr - Finds a value within a string
 * @s: The string to loop over
 * @c: The value to find
 * Return: Address of the first match
 */
char *str_chr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
