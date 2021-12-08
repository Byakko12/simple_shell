#include "shell.h"

/**
 * *_getenv - get path tokenized
 * @name: path
 * Return: path after "="
 */
char *_getenv(const char *name)
{
	int i = 0, dub = 0;
	char **envi = __environ;
	char **strings = NULL;

	while (envi[i])
	{
		strings = _strtok(envi[i], "=");
		dub = _strcmp(strings[0], name);

		if (!dub)
		{
			return (strings[1]);
		}
		i++;
	}
	return (NULL);
}
