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
 * _itoa - convert integer to string
 * @x: integer to convert to string
 * Return: converted string
 */
char *_itoa(int x)
{
	int i = 0, neg = 0, buf = BUFF;
	char *y = NULL;

	y = _realloc(y, 0, buf);
	if (x == 0)
	{
		y[0] = '0', y[1] = '\0';
		return (y);
	}
	else if (x < 0)
	{
		neg = 1, x++, x = -x, i++;
		y[0] = x % 10 + 48 + 1;
		x = x / 10;
	}
	while (x > 0)
	{
		y = ((i >= buf) ? _realloc(y, buf, buf + BUFF) : y);
		if (!y)
			free(y), exit(98);
		buf = (i >= buf) ? buf + BUFF : buf;
		y[i] = x % 10 + 48;
		x /= 10;
		i++;
	}
	if (neg == 1)
	{
		y = ((i >= buf) ? _realloc(y, buf, buf + BUFF) : y);
		if (!y)
			free(y), exit(98);
		buf = (i >= buf) ? buf + BUFF : buf;
		y[i] = '-';
		i++;
	}
	y = _realloc(y, buf, i + 1);
	y[i] = '\0';
	_rev_string(y);
	return (y);
}
/**
 * _realloc - reeallocates a memory block using malloc and free
 * @ptr: pointer to reallocate memory of
 * @old_size: the old size of the pointer
 * @new_size: the new size of the pointer
 * Return: the reassigned pointer (Success)
 *			NULL (Failure) when malloc fails to assign or new_size is 0
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *real = NULL, *temp;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (!ptr)
	{
		return (malloc(new_size));
	}
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	temp = ptr;
	real = malloc(new_size);
	if (!real)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			real[i] = temp[i];
	}
	else if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			real[i] = temp[i];
	}
	free(ptr);
	return (real);
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
