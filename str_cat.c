#include "shell.h"
#include <stdio.h>
#include <string.h>
/**
 * _strcat - This fuction concatenates two strings
 *@dest: this is the first string
 *@src: this is the second string
 * Return: final
 */

char *_strcat(char *dest, char *src)
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
