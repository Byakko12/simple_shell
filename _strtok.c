#include "shell.h"

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

char *_strncpy(char *dest, char *src, int n, int i)
{
	int j = 0;

	for (; i < n && src[i] != '\0'; i++, j++)
		dest[j] = src[i];
	dest[j] = '\0';
	return (dest);
}

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
	return (0);
}

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

char **_strtok(char *string, const char *delim)
{
	char **tokentwo = NULL;
	char r[BUFFSIZE];
	char *token = NULL;
	int i = 0, k = 0, j = 0, tokcount; 

	for (tokcount = 0; string[i]; tokcount++)
	{
		j = num_before_delimit(string, delim, i);
		j += i;
		token = _strncpy(r, string, j, i);
		tokentwo[tokcount] = token;
		printf("%s\n", token);
		i = j;
		k = count_delimit(string, delim, i);
		i += k;
	}
	return (tokentwo);
}
