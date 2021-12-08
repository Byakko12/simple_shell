#include "shell.h"

/**
 * main - print sign $ and receives commands
 *
 * Return: success 0
 */
int main(void)
{
	char *string = NULL, **tokens = NULL;
	size_t n_line = 0;
	int a = 1, tty = 1, bytes_read;

	isatty(STDIN_FILENO) == 0 ? tty = 0 : tty;
	do

	{
		tty == 1 ? write(out, "$h3llc1t4 ", 12) : tty;
		fflush(stdin);
		bytes_read = getline(&string, &n_line, stdin);
		if (bytes_read == -1)
		{
			if (isatty(STDIN_FILENO))
			{
				printf("\n");
				free(string);
			}
			return (-1);
		}
		tokens = _strtok(string, " \n\t");
		if (tokens[0] == NULL)
			free(tokens);
		validate_main(tokens);
		free_arrays(tokens);
	} while (a);
	return (0);
}

/**
 * validate_main - execute command
 * @tokens: command tokenized
 * Return: 1 to succed, -1 if fail
 */
char **validate_main(char **tokens)
{
	int (*functionStr)(char **argv);
	struct stat st;
	char *argument = NULL, **path = NULL;

	if (stat(tokens[0], &st) != 0)
	{
		functionStr = built_in(tokens);
		if (functionStr == NULL)
		{
			path = _getenv("PATH");
			argument = _tokenized_path(path[1], tokens[0]);
			if (argument == NULL)
				perror("Error:");
			execut(argument, tokens);
		}
		else
			functionStr(tokens);
	}
	else
	{
		argument = tokens[0];
		execut(argument, tokens);
	}
	return (tokens);
}
