#include "shell.h"

int main()
{
    char *array = "/bin/ls:/bin/cd:/bin/omg";
    char *string = NULL;
    size_t n_line = 0;
    int bytes_read = 0;
    int a = 1;

    while (a)
    {
        printf("$ ");
        bytes_read = getline(&string, &n_line, stdin);
        _strtok(array, ":")
        
    }

    return (0);
}