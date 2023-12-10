#include <stdio.h>
#include <string.h>
/**
 * _strcmp - compares two strings
 *@s1: The left string
 *@s2: The right string
 * Return: 0 if s1 == s2, -15 if s1 > s2; 15 is s1 < s2
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (*(s1 + i) != '\0')
	{
		if (*(s1 + i) != *(s2 + i))
		{
			if (*(s1 + i) > *(s2 + i))
				return (*(s1 + i) - *(s2 + i));
			else if (*(s1 + i) < *(s2 + i))
				return (*(s1 + i) - *(s2 + i));
			else if (*(s1 + i) == *(s2 + i))
				return (0);
		}
		i++;
	}
	return (0);
}
