#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: string
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
 * *concat_path - check path
 * @command: string
 * @p_tokenized: Array to be comparated
 * Return: string with two strings concat
 */

char *concat_path(char *command, char **p_tokenized)
{
	int i = 0;
	char *slash = "/";
	char *string = NULL;
	struct stat st;

	for (; p_tokenized[i]; i++)
	{
		string = _strcat_memory(p_tokenized[i], slash, command);
		if (!string)
			return (command);
		if (stat(string, &st) == 0)
		{
			free_arrays(p_tokenized);
			free(p_tokenized);
			free(command);
			return (string);
		}
		free(string);
	}
	free_arrays(p_tokenized);
	free(p_tokenized);
	return (command);
}

