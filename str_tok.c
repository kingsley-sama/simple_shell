#include "shell.h"
#include <stdio.h>
#include <string.h>

/**
 * str_tok- Tokenises the string.
 * @str: The string to tokenise.
 * @delimiters: The delimiter in the string.
 *
 * Return:Tokenised string.
 */

char *str_tok(char *str, const char *delimiters)
{
	static char *str_start;
	char *initial_token;

	str_start = NULL;
	if (str == NULL)
	{
	str = str_start;
	}
	while (*str != '\0' && str_chr(delimiters, *str) != NULL)
	{
	str++;
	}
	if (*str == '\0')
	{
	str_start = NULL;
	return (NULL);
	}

	initial_token = str;
	while (*str != '\0' && str_chr(delimiters, *str) == NULL)
	{
	str++;
	}
	if (*str == '\0')
	{
	str_start = str;
	}
	else
	{
	*str = '\0';
	str_start = str + 1;
	}
	return (initial_token);
}
