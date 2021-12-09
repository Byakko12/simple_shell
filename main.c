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
	int a = 0, tty = 1, bytes_read, b = 0;

	isatty(STDIN_FILENO) == 0 ? tty = 0 : tty;

	while (a == 0)
	{
		a = 1;
		tty == 1 ? write(out, "$ ", 2) : tty;
		fflush(stdin);
		bytes_read = getline(&string, &n_line, stdin);
		if (bytes_read == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (-1);
		}
		if (bytes_read == 0)
			a = 0;
		if (bytes_read > 0)
		{
			b = count_chars_words(string, DELIMIT);
			tokens = _strtok(string, DELIMIT);
			a = validate_main(tokens, string, b);
		}
		if (a == 0)
			free_all(tokens, string);
	}
	return (0);
}

/**
 * validate_main - execute command
 * @tokens: command tokenized
 * Return: 1 to succed, -1 if fail
 */
int validate_main(char **tokens, char *str, int n)
{
	int (*functionStr)(char **argv, char *string, int n);
	struct stat st;
	char *argument = NULL;

	if (stat(tokens[0], &st) != 0)
	{
		functionStr = built_in(tokens);
		if (functionStr == NULL)
		{
			argument = concat_path(tokens[0], _strtok(_getenv("PATH"), ":"));
			if (argument == NULL)
				perror("Error:");
			execut(argument, tokens);
		}
		else
			functionStr(tokens, str, n);
	}
	else
	{
		argument = tokens[0];
		execut(argument, tokens);
	}
	return (0);
}
