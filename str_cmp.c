#include "shell.h"
#include <stdio.h>

/**
 * str_cmp - Compares dest string with src string.
 * @dest: The destination string
 * @src: The source string.
 *
 * Return: 0(success)
 */
int str_cmp(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
	if (dest[i] != src[i])
	return (-1);
	i++;
	}
	return (0);
}
