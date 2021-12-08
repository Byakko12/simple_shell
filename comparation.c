#include "shell.h"

/**
 * built_in - print sign $ and receives commands
 * @argv: commands to be comparated
 * Return: function to be called, or NULL if fails
 */
int (*built_in(char **argv))(char **tokens)
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
 * *_tokenized_path - tokenize path
 * @path: path to be tokenized
 * @token: arguments to store path
 * Return: tokens with path or NULL
 */
char *_tokenized_path(char *path, char *token)
{
	int i = 0;
	char **tokens = NULL;
	char *slash = "/";
	char *string = NULL;

	tokens = _strtok(path, ":");
	for (; tokens[i]; i++)
	{
		string = _strcat_memory(slash, token);
		tokens[i] = _strcat_memory(tokens[i], string);
		if (tokens[i] == NULL)
		{
			break;
		}
	}
	string = stat_path(tokens);
	return (string);
}

/**
 * *stat_path - validate path
 * @argv: receives arguments
 * Return: tokens with path or NULL
 */
char *stat_path(char **argv)
{
	int i = 0;
	struct stat st;

	for (i = 0; argv[i]; i++)
	{
		if (stat(argv[i], &st) == 0)
		{
			return (argv[i]);
		}
	}

	return (NULL);
}

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
