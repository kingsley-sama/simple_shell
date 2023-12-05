#include "shell.h"
#include <stdio.h>

/**
 *str_cmp - compares dest string with src string
 *@dest: destination string
 *@src: source string
 *Return: 0 on succes
 */
int str_cmp(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		if (dest[i] != src[i] )
			return (0);
		i++;
	}
	return (0);
}
