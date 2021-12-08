#include "shell.h"

int main(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;
    (void)env;
    char *argument = NULL;
    char *path = NULL;
    char *string = NULL;
    size_t n_line = 0;
    char **tokens = NULL;
    int bytes_read = 0, a = 1;
    int (*functionStr)(char **argv);
    struct stat st;

    do
    {
        write(out, "$ ", 4);
        fflush(stdin);
        bytes_read = getline(&string, &n_line, stdin);
        tokens = _strtok(string, " \n\t");

        if (stat(tokens[0], &st) != 0)
        {
            printf("%d", bytes_read);
            functionStr = built_in(tokens); /*
             a = functionStr(tokens);*/
            if (functionStr == NULL)
            {
                path = _getenv("PATH");
                printf("%s\n", path);
                argument = _tokenized_path(path, tokens[0]);
                printf("%s\n", argument);
                if (argument == NULL)
                {
                    perror("Error:");
                    continue;
                }
                if (stat(argument, &st) == 0)
                {
                    execve(argument, tokens, NULL);
                }
            }
        }
    } while (a);
    return (0);
}