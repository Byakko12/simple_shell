#include "shell.h"

char *stat_path(int argc, char **argv)
{
    char **env = __environ;
    struct stat st;

    if (stat(argv[0], &st) == 0)
    {
        return();
    }
    
}

char *exec_commands(char **argv, int status)
{

    write(out, "Before execve\n", 15);
    if (execve(argv[0], argv, NULL) == -1)
    {
        write(out, "Error:", 7);
    }
    write(out, "After execve\n", 14);
}