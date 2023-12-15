#include "shell.h"


/**
 * strn_cmp - function that compares n amount of characters of two strings
 * @s1: first string
 * @s2: second string
 * @n: amount of characters to compare
 *
 * Return: 1 if the strings don't match otherwise 0
 */
int strn_cmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (s1 == NULL)
	return (-1);

	for (i = 0; i < n && s2[i]; i++)
	{
	if (s1[i] != s2[i])
	{
	return (1);
	}
	}
	return (0);
}

/**
 * str_dup - duplicate a string
 * @str: string
 *
 * Return: duplicated string or Null if failed
 */
char *str_dup(char *str)
{
	size_t length, i;
	char *str2;

	length = str_len(str);
	str2 = malloc(sizeof(char) * (length + 1));
	if (!str2)
	{
	return (NULL);
	}
	for (i = 0; i <= length; i++)
	{
	str2[i] = str[i];
	}
	return (str2);
}
/**
 * str_cpy - function that copies a string
 * @dest: destination
 * @src: source
 *
 * Return: destination
 */
char *str_cpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
	dest[i] = src[i];
	i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * str_cat - function that concatenates two strings
 * @dest: first string
 * @src: second string
 *
 * Return: first string + second string
 */
char *str_cat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
	*dest = *src;
	dest++;
	src++;
	}
	*dest = '\0';
	return (s);
}

/**
 * str_chr - function that locates character in a string
 * @s: string to be searched
 * @c: character to be located
 *
 * Return: pointer to character
 */
char *str_chr(char *s, char c)
{
	do {
	if (*s == c)
	{
	break;
	}
	} while (*s++);
	return (s);
}
