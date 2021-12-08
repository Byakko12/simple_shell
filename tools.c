#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: array of strings
 * Return: return length
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}

/**
 * *_strncpy - copy n size of bites of string starting in i
 * position
 * @delim: delimiter
 * @src: Array to add
 * @n: size of array
 * @i: position to start
 * Return: dest with two strings concat
 */
char *_strncpy(char *delim, char *src, int n, int i)
{

	int j = 0, count = num_before_delimit(src, delim, i);
	char *dest = malloc(sizeof(char) * count + 1);

	if (!dest)
	{
		printf("CANTIDAD LETRA = %d\n", count);
		return (NULL);
	}
	for (; i < n && src[i] != '\0'; i++, j++)
		dest[j] = src[i];
	dest[j] = '\0';
	return (dest);
}

/**
 * *_strcmp - compares two strings.
 * @s1: String number 1
 * @s2: String number 2
 * Return: return positive if s1 is greater than s2
 * negatives if is less or 0 if is equal
 */
int _strcmp(const char *s1, const char *s2)
{
	int i = 0, temp;

	for (; s1[i] != '\0'; i++)
	{
		if (s1[i] == s2[i])
		{
			temp = 0;
		}
		else
		{
			temp = (s1[i] - s2[i]);
			break;
		}
	}
	return (temp);
}

/**
 * *_strcat_memory - concatenates two strings with memory
 * @dest: Array buffer
 * @src: Array to append
 * Return: string with two strings concat
 */
char *_strcat_memory(char *dest, char *src)
{
	int i, j = 0;
	int count = _strlen(dest) + _strlen(src);
	char *string = malloc(sizeof(char *) * count + 1);

	if (string == NULL)
	{
		return (NULL);
	}

	for (i = 0; dest[i] != '\0'; i++)
	{
		string[i] = dest[i];
	}
	for (; i <= count; i++, j++)
	{
		string[i] = src[j];
	}
	string[i] = '\0';
	return (string);
}
