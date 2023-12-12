#include "shell.h"
#include <stdio.h>
#include <string.h>

/**
 * _strcat - Concatenates two strings.
 * @dest: The first string.
 * @src: The second string.

 * Return: Modified string.
 */

char *str_cat(char *dest, const char *src)
{
	int i, j, k;

	j = strlen(dest);
	k = strlen(src);
	for (i = 0; i < k; i++)
	{
		*(dest + (i + j)) = src[i];
	}
	*(dest + (i + j)) = '\0';
	return (dest);
}
