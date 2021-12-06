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
	for (; i < n; i++, j++)
		dest[j] = '\0';
	return (dest);
}

int num_before_delimit(char *string, char *delim, int n)
{
	int i = n, j;
	/*char *token = NULL;*/
	/*char **tokenized = NULL;*/

	for (; string[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (string[i] == delim[j])
				return (i);
		}
	}
	return (0);
}

int count_delimit(char *string, char *delim, int n)
{
	int i, k, o = 0;
	/*char *token = NULL;*/
	/*char **tokenized = NULL;*/

	for (k = 0, i = n; string[i]; i++)
	{
		k = check_coincidence(delim, string[i]);
		if (k == 0)
			break;
		o++;
	}
	return (o);
}

/*
char **_strtok(char *string, const char *delim)
{
	int i, j
	char *token = NULL;
	char **tokenized = NULL;

	for (i = 0; string[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (string[i] != delim[j])
			{
				token[k] = string[i];
				k++;
			}
			if (string[i] == delim[j])
			{
				i++;
				break;
			}
		}
		tokenized[0] = token;
		token = NULL;
		k = 0;
	}
	return (tokenized);
}*/

int main()
{
	char r[BUFFSIZE];
	char *tokenized = "abcdef:////:/:/:///abcdefg////::";
	int i = 0, k = 0, j = 0/*, total*/;
	char *f = NULL;
	/*char **strings = NULL;*/

	/*strings = _strtok(tokenized, ":/");*/
	/*for (; strings[i]; i++)
	{
		printf("%s\n", strings[i]);
	}*//*
	for (; tokenized[];)
	{
		j = num_before_delimit(tokenized, ":/", total);
		printf("%d\n", j);
		total += j;
		f = _strncpy(r, tokenized, total, total - j);
		printf("%s\n", f);
		k = count_delimit(tokenized, "/:", total);
		printf("%d\n", k);
		total = j + k;
		printf("%d\n", j);
	}*/
	i = num_before_delimit(tokenized, ":/", 0);
	f = _strncpy(r, tokenized, i, 0);
	k = count_delimit(tokenized, "/:", i);
	j = k + i;
	printf("k = %d\n", k);
	printf("%s\n", f);
	printf("i = %d\n", i);
	printf("j = %d\n", j);
	i = num_before_delimit(tokenized, ":/", j);
	printf("i2 = %d\n", i);
	f = _strncpy(r, tokenized, i, j);
	printf("f2 = %s\n", f);
	k = count_delimit(tokenized, "/:", i);

	return (0);
}