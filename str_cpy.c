#include "shell.h"
/**
 *str_cpy - Copy string from one location to another.
 *@src: The source string.
 *@dest: The destination string.
 *
 *Return: The destination string.
 */
char *str_cpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
	dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
