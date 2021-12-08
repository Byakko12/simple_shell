#include "shell.h"

/**
 * cd_built_in - change directory
 * @argv: parameter
 * Return: 1 if success
 */
int cd_built_in(char **argv)
{
	(void)argv;
	printf("entro el cd");
	return (1);
}
/**
 * help_built_in - display help to sh
 * @argv: parameter
 * Return: 1 if success
 */
int help_built_in(char **argv)
{
	(void)argv;
	printf("entro el help");
	return (1);
}

/**
 * env_built_in - display environ
 * @argv: parameter
 * Return: 1 if success
 */
int env_built_in(char **argv)
{

	int i;
	char **envi = __environ;
	(void)argv;

	for (i = 0; envi[i]; i++)
	{
		printf("%s\n", envi[i]);
	}
	return (1);
}

/**
 * exit_built_in - exit of program
 * @argv: parameter
 * Return: 1 if success
 */
int exit_built_in(char **argv)
{
	(void)argv;
	printf("entro a exit");
	return (1);
}
