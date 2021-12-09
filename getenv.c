#include "shell.h"

/**
 * *_strcat_memory - concatenates two strings with memory
 * @dest: Array buffer
 * @src: Array to append
 * Return: string with two strings concat
 */
char *_strcat_memory(char *t_path, char *sls, char *command)
{
	int i, j, k = 0;
	int count = _strlen(t_path) + _strlen(sls) + _strlen(command);
	char *string = malloc(sizeof(char *) * count + 1);

	if (string == NULL)
		return (NULL);

	for (i = 0; t_path[i] != '\0'; i++)
		string[i] = t_path[i];
	for (j = 0; sls[j] != '\0'; j++, i++)
		string[i] = sls[j];
	for (k = 0; i <= count; i++, k++)
		string[i] = command[k];
	string[i] = '\0';
	return (string);
}

/**
 * _atoi - convert a string to an integer
 * @s: Array that contains de string
 * Return: return numbers convert to integers
 */
int _atoi(char *s)
{
	unsigned int i = 0, sign_counter = 0, numbers = 0;

	if (s[i] == 0)
		return (0);
	for (; s[i] != '\0' && (s[i] < '0' || s[i] > '9'); i++)
	{
		if (s[i] == '-')
			sign_counter++;
	}
	for (; s[i] >= 48 && s[i] <= 57; i++)
		numbers = (numbers * 10 + (s[i] - 48));
	if (sign_counter % 2 == 1)
		numbers *= -1;
	return (numbers);
}

/**
 * *_getenv - get path tokenized
 * @name: path
 * Return: path after "="
 */
char *_getenv(char *name)
{
	int i = 0, j = 0;
	char **environ = __environ; 

	for (; environ[i]; i++)
	{
		for (; name[j]; j++)
		{
			if (environ[i][j] != name[j])
				break;
		}
		if (name[j] == '\0' && environ[i][j] == '=')
			return (&environ[i][j + 1]);
	}
	return (NULL);
}
