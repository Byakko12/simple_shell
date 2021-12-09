#include "shell.h"

/**
 * main - print sign $ and receives commands
 *
 * Return: success 0
 */
int main(void)
{
	size_t n_line = 0;
	int a = 0, tty = 1, bytes_read, b = 0;

	isatty(STDIN_FILENO) == 0 ? tty = 0 : tty;
	do

	{
		char *string = NULL, **tokens = NULL;

		a = 1;
		tty == 1 ? write(out, "$ ", 2) : tty;
		fflush(stdin);
		bytes_read = getline(&string, &n_line, stdin);
		if (bytes_read == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(string);
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
		free_all(tokens, string);
	} while (a == 0);
	return (0);
}

/**
 * validate_main - execute command
 * @tokens: command tokenized
 * @str: command
 * @n: counter
 * Return: 1 to succed, -1 if fail
 */
int validate_main(char **tokens, char *str, int n)
{
	int (*functionStr)(char **argv, char *string, int n);
	struct stat st;

	if (stat(tokens[0], &st) != 0)
	{
		functionStr = built_in(tokens);
		if (functionStr == NULL)
		{
			tokens[0] = concat_path(tokens[0], _strtok(_getenv("PATH"), ":"));
			if (tokens[0] == NULL)
				perror("Error:");
			execut(tokens[0], tokens);
		}
		else
			functionStr(tokens, str, n);
	}
	else
		execut(tokens[0], tokens);
	return (0);
}
