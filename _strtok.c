#include "shell.h"

/**
 * check_coincidence - checks for coincidence
 * @string: string
 * @b: character
 * Return: 1 if found coincidence, 0 if not
 */
int check_coincidence(char *string, char b)
{
	int i;

	for (i = 0; string[i]; i++)
	{
		if (string[i] == b)
			return (1);
	}
	return (0);
}

/**
 * num_before_delimit - count before delimiter
 * @string: string
 * @delim: delimiter
 * @n: size
 * Return: count before delimiter
 */
int num_before_delimit(char *string, char *delim, int n)
{
	int i = n, j, count;

	for (count = 0; string[i]; i++, count++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (string[i] == delim[j])
				return (count);
		}
	}
	return (count);
}

/**
 * count_delimit - count delimiters
 * @string: string
 * @delim: delimiter
 * @n: size
 * Return: size of delimiters
 */
int count_delimit(char *string, char *delim, int n)
{
	int i, k, o = 0;

	for (k = 0, i = n; string[i]; i++)
	{
		k = check_coincidence(delim, string[i]);
		if (k == 0)
			break;
		o++;
	}
	return (o);
}

/**
 * count_chars_words - count only string without delimiter
 * @string: string
 * @delim: delimiter
 * Return: count of words
 */
int count_chars_words(char *string, char *delim)
{
	int i = 0, j = 0, k = 0, count = 0;

	while (string[i])
	{
		j = num_before_delimit(string, delim, i);
		count += j, j += i;
		i = j;
		k = count_delimit(string, delim, i);
		i += k;
	}
	return (count);
}

/**
 * **_strtok - store an array of tokens
 * @string: string
 * @delim: delimiter
 * Return: array of tokens
 */
char **_strtok(char *string, char *delim)
{
	int i = 0, k = 0, j = 0, count,
		count_words = count_chars_words(string, delim);
	char **tokens = malloc(sizeof(char *) * (count_words + 1));

	if (!tokens)
		printf("malloc tokens F"), exit(100);
	for (count = 0; string[i]; count++)
	{
		j = num_before_delimit(string, delim, i);
		j += i;
		tokens[count] = _strncpy(delim, string, j, i);
		i = j;
		k = count_delimit(string, delim, i);
		i += k;
	}
	tokens[count] = NULL;
	return (tokens);
}
