#include "shell.h"
#include <stdio.h>

/**
 *_strchr - Finds a value within a string
 *@s: The string to loop over
 *@c: The value to find
 *Return: Address of the first match
 */
char *_strchr(char *s, char c)
{
	int i = 0;
	char *array;

	while (s[i] != '\0')
	{
	if (s[i] == c)
	array[i] = s[i + 1];
	}

	return (NULL);
}
