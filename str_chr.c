#include "shell.h"
#include <stdio.h>

/**
 *_strchr - finds a value within a string
 *@s: this is the string to loop over
 *@c: this is the value to find
 *Return: address of the first match
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		else if (*(s + 1) == c)
			return (s + 1);

		s++;

	}
	return (s + 1);
}
