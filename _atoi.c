#include "monty.h"
/**
 * _atoi - converts string to an integer
 * @s: string pointer
 *
 * Return: 0 if there're no numbers in the string,
 * otherwise return the integer
 */
int _atoi(char *s)
{
	unsigned int num = 0, n_count = 0;

	while (*s)
	{
		if (*s == '-')
			n_count++;
		if (*s >= 48 && *s <= 57)
			num = (num * 10) + (*s - 48);
		s++;
	}

	return (n_count % 2 == 0 ? num : -num);
}

/**
 * _isnumeric - checks if a string is a digit
 * @c: string to be tested
 * Return:  0 (Success)
 *			1 (Failure)
 */
int _isnumeric(char *c)
{
	while (*c)
	{
		if (*c < 48 || *c > 57)
			return (1);
		c++;
	}
	return (0);
}
/**
 * _rev_string - function that reverses a string.
 * @s: pointer to a string.
 */
void _rev_string(char *s)
{
	int i = 0, l = 0;
	char temp;

	l = _strlen(s);
	while (i < l / 2)
	{
		temp = s[i];
		s[i] = s[l - i - 1];
		s[l - i - 1] = temp;
		i++;
	}
}
