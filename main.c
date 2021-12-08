#include "shell.h"

int main(int argc, char **argv, char **env)
{

	char *argument = NULL;
	char *path = NULL;
	char *string = NULL;
	size_t n_line = 0;
	char **tokens = NULL;
	int a = 1, tty = 1;
	int (*functionStr)(char **argv);
	struct stat st;
	(void)argc, (void)argv, (void)env;

	if (isatty(STDIN_FILENO) == 0)
	{
		tty = 0;
	}
	do
	{
		if (tty == 1)
		{	
			write(out, "$h3llc1t4 ", 12);
		}
        fflush(stdin);
		getline(&string, &n_line, stdin);
		tokens = _strtok(string, " \n\t");

		if (stat(tokens[0], &st) != 0)
		{
			functionStr = built_in(tokens);
			if (functionStr == NULL)
			{
				path = _getenv("PATH");
				argument = _tokenized_path(path, tokens[0]);
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