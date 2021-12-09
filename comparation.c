#include "shell.h"

/**
 * built_in - print sign $ and receives commands
 * @argv: commands to be comparated
 * Return: function to be called, or NULL if fails
 */
int (*built_in(char **argv))(char **tokens, char *string, int n)
{
	size_t i = 0;

	template command_array[] = {
		{"cd", cd_built_in},
		{"help", help_built_in},
		{"env", env_built_in},
		{"exit", exit_built_in},
		{NULL, NULL}};

	while ((command_array[i].comparated) != NULL)
	{
		if (_strcmp(command_array[i].comparated, argv[0]) == 0)
			return (command_array[i].functionStr);
		i++;
	}
	return (NULL);
}

/**
 * *store_tokens - tokenize path
 * @path: path to be tokenized
 * @token: arguments to store path
 * Return: tokens with path or NULL
 */
/*
char *store_tokens(char **argv)
{

	argv[0] = concat_path(argv[0], _strtok(_getenv("PATH")), ":")
		
		return (argv[0]);
}*/

/**
 * exec_command - execute command
 * @argv: receives arguments
 * Return: 0 if success or 1 if fails
 */
int exec_command(char **argv)
{
	pid_t child_pid;
	int status = 0;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child_pid == 0)
	{
		execve(argv[0], argv, NULL);
		exit(0);
	}
	else
		wait(&status);

	return (0);
}
