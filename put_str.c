#include "shell.h"

/**
 * put_char - function that writes the character to stdout
 * @c: The character to print
 * Return: character to standard output
 */
int put_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * puts - function that prints a string
 * @str: pointer to string
 * Return: void
 */
void put_s(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		put_char(str[i]);
	}
	put_char('\n');
}

/**
 * strn_cpy - function that copies a string
 * @dest: destination string
 * @src: source string
 * @n: number of charaters to be copied
 * Return: copied strings
 */
char *strn_cpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && *(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	while (i < n)
	{
		*(dest + i) = '\0';
		i++;
	}
	return (dest);
}

/**
 * str_len - function that counts the length of a string
 * @s: string input
 * Return: length of string
 */
int str_len(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		continue;
	}
	return (i);
}

/**
 * ato_i - function to convert string to a integer
 * @s: string input
 * Return: converted integer
 */
int ato_i(char *s)
{
	int i = 0, j = 1, k;
	unsigned int l = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			return (2);
		}
		k = s[i] - '0';

		if (l > 0 && !(k >= 0 && k <= 9))
			break;

		if (k >= 0 && k <= 9)
			l = l * 10 + k;

		i++;
	}
	l *= j;
	return (l);
}
