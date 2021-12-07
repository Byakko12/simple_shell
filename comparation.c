#include "shell.h"

char (*built_in(char **argv))(char **tokens)
{
    size_t i = 0;

    template command_array[] = {
        {"cd", cd_built_in},
        {"help", help_built_in},
        {"exit", exit_built_in},
        {NULL, NULL}};

    while ((command_array[i].comparated) != NULL)
    {
        if (strcmp(command_array[i].comparated, argv[0]) == 0)
        {
            return (command_array[i].functionStr);
        }
    }
    return (NULL);
}

char *_token_after(char *path)
{
    int i = 0;
    char **tokens = NULL;

    for (; tokens[i] = _strtok(path, ":"); path = NULL, i++)
    {
        printf("%s\n", tokens[i]);
        if (tokens[i] == NULL)
        {
            break;
        }
    }
    return (tokens);
}

char *stat_path(char **argv, char **env)
{
    int i = 0;
    struct stat st;

    for (; argv[i]; i++)
    {
        if (stat(argv[i], &st) == 0)
        {
            return (exec_command(argv[0], argv));
        }
        else
        {
            perror("Error: Path not found");
        }
    }
}

char *exec_command(char **argv, int status)
{
    pid_t child_pid;
    int status, i;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error:");
        return (1);
    }
    if (child_pid == 0)
        execve(argv[0], argv, NULL);
    else
        wait(&status);

    return (0);
}
