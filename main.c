#include "shell.h"

/**
 * main - print sign $ and receives commands
 *
 * Return: success 0
 */
int main(void)
{
	char *argument = NULL, *path = NULL, *string = NULL, **tokens = NULL;
	size_t n_line = 0;
	int a = 1, tty = 1, bytes_read;
	int (*functionStr)(char **argv);
	struct stat st;

	if (isatty(STDIN_FILENO) == 0)
		tty = 0;
	do

	{
		if (tty == 1)
		{
			write(out, "$h3llc1t4 ", 12);
		}
		fflush(stdin);
		bytes_read = getline(&string, &n_line, stdin);
		if (bytes_read == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			/*write("\n", 1);*/
			return (-1);
		}
		tokens = _strtok(string, " \n\t");
		if (stat(tokens[0], &st) != 0)
		{
			functionStr = built_in(tokens);
			if (functionStr == NULL)
			{
				path = _getenv("PATH");
				argument = _tokenized_path(path, tokens[0]);
				free(path);
				if (argument == NULL)
				{
					perror("Error:");
					continue;
				}
				execut(argument, tokens);
			}
			else
				a = functionStr(tokens);
		}
		else
		{
			argument = tokens[0];
			execut(argument, tokens);
		}
		free(string);
	} while (a);
	return (0);
}
