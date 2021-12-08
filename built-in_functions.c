#include "shell.h"

int cd_built_in(char **argv)
{
    (void) argv;
    printf("entro el cd");
    return (1);
}

int help_built_in(char **argv)
{
    (void) argv;
    printf("entro el help");
    return(1);
}

int exit_built_in(char **argv)
{
    (void) argv;
    printf("entro a exit");
    return(1);
}