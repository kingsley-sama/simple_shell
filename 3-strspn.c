#include "main.h"
#include <stdio.h>

/**
 *_strchr - finds a value within a string
 *@s: this is the string to loop over
 *@c: this is the value to find
 *Return: address of the first match
 */
char *_strchr(char *s, char c)
{
	int i;

	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
			return ((s + i));

	}
	return (NULL);
}
