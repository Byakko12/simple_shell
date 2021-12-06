#include "shell.h"

int check_coincidence(char* string, char b)
{
	int i;
	
	for (i = 0 ;string[i]; i++) 
	{
		if (string[i]  == b) 
			return (1);
	}
	return(0);
}

char *_strncpy(char *dest, char *src, int n)
{
    int i = 0;

    for (; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    for (; i < n; i++)
        dest[i] = '\0';
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
				return(i);
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
		printf("num = %d\n", o);
	}
	return (o);
}

/*
int _strlen_delim(char *string, int)
{

    while (string)
    {
    }
}


*/
/*char **_strtok(char *string, const char *delim)
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
	char *tokenized = "abcdef:////:/:/:///abcdef////::";
	int i = 0, k = 0;
	char *f = NULL;
	/*char **strings = NULL;*/

	/*strings = _strtok(tokenized, ":/");*/
	/*for (; strings[i]; i++)
	{
		printf("%s\n", strings[i]);
	}*/
	i = num_before_delimit(tokenized, ":", 0);
	f = _strncpy(r, tokenized, i);
	k = count_delimit(tokenized, "/:", i);
	printf("k = %d\n", k);
	printf("%s\n", f);
	printf("i = %d\n", i);
	
	return (0);
}