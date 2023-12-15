#include "shell.h"

/**
 * str_cmp - function that compares two string
 * @s1: first string
 * @s2: second string.
 *
 * Return: 0 if identical otherwise how much diffrent
 */
int str_cmp(char *s1, char *s2)
{
	int cmp = 0, i, len1, len2;

	len1 = str_len(s1);
	len2 = str_len(s2);

	if (s1 == NULL || s2 == NULL)
	return (1);

	if (len1 != len2)
	return (1);

	for (i = 0; s1[i]; i++)
	{
	if (s1[i] != s2[i])
	{
	cmp = s1[i] - s2[i];
	break;
	}
	else
	continue;

	}
	return (cmp);
}

/**
 * is_alpha - function to check if c is alphabet
 * @c: character to check.
 *
 * Return: 1 if true 0 if false
 */
int is_alpha(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
	{
	return (1);
	}
	else
	{
	return (0);
	}
}

/**
 * ito_a - funciton that convert integer to character
 * @n: integer to convert.
 *
 * Return: character pointer
 */
char *ito_a(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	len = intlen(n);
	s = malloc(len + 2);

	if (!s)
	{
	free(s);
	return (NULL);
	}
	*s = '\0';

	while (n / 10)
	{
	s[i] = (n % 10) + '0';
	n /= 10;
	i++;
	}

	s[i] = (n % 10) + '0';
	rev(s, len);
	s[i + 1] = '\0';

	return (s);
}

/**
 * rev - function reverse an array
 * @arr: array to reverse
 * @len: length of array.
 *
 * Return:Void.
 */
void rev(char *arr, int len)
{
	int i;
	char tmp;

	for (i = 0; i < (len / 2); i++)
	{
	tmp = arr[i];
	arr[i] = arr[(len - 1) - i];
	arr[(len - 1) - i] = tmp;
	}
}

/**
 * intlen - function that determine length of integer
 * @num: given integer.
 *
 * Return: length of integer
 */
int intlen(int num)
{
	int len = 0;

	while (num != 0)
	{
	len++;
	num /= 10;
	}
	return (len);
}
