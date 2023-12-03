#include "shell.h"
/**
 *str_cpy - copies a string and return the copy
 *@src: this is the source string
 *@dest: this is the destination string
 *Return: the destination string
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
  
