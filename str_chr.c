#include "shell.h"
#include <stdio.h>
/**
 *_strchr - finds a value within a string
 *@s: this is the string to loop over
 *@c: this is the value to find
 *Return: address of the first match
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
