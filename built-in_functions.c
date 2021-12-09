#include "shell.h"

/**
 * cd_built_in - change directory
 * @argv: parameter
 * Return: 1 if success
 */
int cd_built_in(char **argv, char *string, int n)
{
	(void)string;
	(void)n;
	chdir(argv[1]);
	return (1);
}

/**
 * help_built_in - display help to sh
 * @argv: parameter
 * Return: 1 if success
 */
int help_built_in(char **argv, char *string, int n)
{
	(void)argv;
	(void)string;
	(void)n;
	
	printf("entro el help\n");
	return (1);
}

/**
 * env_built_in - display environ
 * @argv: parameter
 * Return: 1 if success
 */
int env_built_in(char **argv, char *string, int n)
{

	int i;
	char **envi = __environ;
	(void)argv;
	(void)string;
	(void)n;

	for (i = 0; envi[i]; i++)
	{
		write(out, envi[i], _strlen(envi[i]));
		write(out, "\n", 1);
	}
	return (1);
}

/**
 * is_number - verifies if is number
 * @argv: Array of strings
 * Return: return 1 if has numbers or 0 if it fails
 */
int is_number(char **argv)
{
	int j;

	for (j = 0; argv[0][j]; j++)
	{
		if (argv[0][j] < 48 || argv[0][j] > 57)
			return (1);
	}
	return (0);
}

/**
 * exit_built_in - exit of program
 * @argv: parameter
 * @string: command
 * Return: 1 if success
 */
int exit_built_in(char **argv, char *string, int n)
{
	int i;

	if (n > 1)
	{
		if (_atoi(argv[1]) < 0 || is_number(argv) != 0)
		{
			write(out, "./hsh: ", 7);
			write(out, ": ", 2);
			write(out, argv[0], _strlen(argv[0]));
			write(out, ": Illegal number: ", 18);
			write(out, argv[1], _strlen(argv[1]));
			write(out, "\n", 1);
			free_all(argv, string);
			exit(2);
		}
		i = _atoi(argv[1]);
		free_all(argv, string);
		exit(i);
	}
	else
	{
		free_all(argv, string);
		exit(0);
	}
	return (1);
}
