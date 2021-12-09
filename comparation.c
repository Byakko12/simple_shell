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
 * execut - execute command
 * @argument: path tokenized
 * @tokens: command tokenized
 * Return: 1 to succed, -1 if fail
 */
int execut(char *argument, char **tokens)
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
		tokens[0] = argument;
		execve(tokens[0], tokens, NULL);
		exit(0);
	}
	else
		wait(&status);
	return (1);
}
