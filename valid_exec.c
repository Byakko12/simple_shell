#include "shell.h"

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
