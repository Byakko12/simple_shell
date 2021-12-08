#include "shell.h"

int (*built_in(char **argv))(char **tokens)
{
    size_t i = 0;

    template command_array[] = {
        {"cd", cd_built_in},
        {"help", help_built_in},
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
/*
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
}*/

char *_tokenized_path(char *path, char *token)
{   
    int i = 0;
    char **tokens = NULL;
    char *slash = "/";
    char *string = NULL;
    tokens = _strtok(path, ":");

    for (; tokens[i]; i++)
    {
        string = _strcat_memory(slash, token);         //  /ls
        tokens[i] = _strcat_memory(tokens[i], string); //  /usr/bin
        if (tokens[i] == NULL)
        {
            break;
        }
    }
    string = stat_path(tokens);
    return (string);
}

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
