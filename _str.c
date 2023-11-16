#include "monty.h"
/**
 * _strlen - function that returns the length of a string.
 * @s: pointer to a string.
 * Return: length of string s.
 */
int _strlen(char *s)
{
	int  l = 0;

	while (s[l])
		l++;
	return (l);
}
/**
 * _strcpy - function that copies the string pointed to by src,
 * Description: including the terminating null byte (\0),
 * to the buffer pointed to by dest.
 * @src: pointer to the source string.
 * @dest: pointer to the destination string.
 * Return: the pointer to destination.
 */
char *_strcpy(char *dest, char *src)
{
	int l = 0;

	while (src[l])
	{
		dest[l] = src[l];
		l++;
	}
	dest[l] = 0;
	return (dest);
}
/**
 * _strcat - function that concatenates two strings
 * Description: by appending the src string to the dest string,
 * overwriting the terminating null byte (\0)
 * at the end of dest, and then adds a terminating
 * null byte
 * @src: pointer to the source string.
 * @dest: pointer to the destination string.
 * Return: the pointer to destination.
 */
char *_strcat(char *dest, char *src)
{
	int l = 0, m = 0;

	for (; dest[l]; l++)
		;
	while (src[m])
	{
		dest[l + m] = src[m];
		m++;
	}
	dest[l + m] = 0;
	return (dest);
}


/**
 * _strncat - function that concatenates two strings
 * Description: by appending the n bytes from src string to the dest string,
 * overwriting the terminating null byte (\0)
 * at the end of dest, and then adds a terminating
 * null byte unless src contains n or more bytes
 * @src: pointer to the source string.
 * @dest: pointer to the destination string.
 * @n: number of bytes taken from src
 * Return: the pointer to destination.
 */
char *_strncat(char *dest, char *src, int n)
{
	int l = 0, m = 0;

	for (; dest[l]; l++)
		;
	while (m < n && src[m])
	{
		dest[l + m] = src[m];
		m++;
	}
	dest[l + m] = 0;
	return (dest);
}



/**
 * _strcmp - compares n chars in both strings.
 * @s1: 1st string.
 * @s2: 2nd string.
 * Return: difference between the total value based on ASCII of both strings.
 * 0 if they match until n.
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (*(s1 + i) == *(s2 + i) && *(s2 + i) != '\0' && *(s1 + i) != '\0')
	{
		i++;
	}
	return (*(s1 + i) - *(s2 + i));
}


