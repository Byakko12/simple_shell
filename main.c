#include "shell.h"

int main(int argc, char **argv, char **env)
{

    char *string = NULL;
    size_t n_line = 0;
    char *tokens[1024];
    int bytes_read = 0, a = 1;
    int (*functionStr)(char **argv);

    do
    {
        write(out, "$ ", 4);
        bytes_read = getline(&string, &n_line, stdin);
        tokens = _strtok(array, ":")
        stat_path(tokens, env)

    } while (a)

        return (0);
}