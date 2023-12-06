#include "shell.h"
#include <stdio.h>
#include <string.h>

/**
 * d_strtok- Parses a string.
 * @str: The string source.
 * @dl:The delimiter.
 * Return:0
 */
char *d_strtok(char *str, const char *dl)
{
	static char *p;
	char *tok = p;

	p = NULL;

	if (str != NULL)
	p = str;

	if (p == NULL || *p == '\0')
	return (NULL);

	while (*p != '\0' && strchr(dl, *p) != NULL)
	p++;

	if (*p == '\0')
	return (NULL);

	while (*p != '\0' && strchr(dl, *p) == NULL)
	p++;

	if (*p != '\0')
	{
	*p = '\0';
	p++;
	}
	return (tok);

}
