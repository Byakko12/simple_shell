#ifndef _HEADER_SHELL_
#define _HEADER_SHELL_

/*libraries*/
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/*MACROS*/
#define BUFFSIZE 1024
#define out STDOUT_FILENO

typedef struct commands
{
    char *comparated;
    int (*functionStr)(char **argv);

} template;
char **_strtok(char *string, const char *delim);
int check_coincidence(char *string, char b);
char *_strncpy(char *dest, char *src, int n, int initial);
int num_before_delimit(char *string, char *delim, int n);
int count_delimit(char *string, char *delim, int n);
char *stat_path(char *, char **argv);
int cd_built_in();
int help_built_in();
int exit_built_in();
char (*built_in(char **argv))(char **tokens);
char *_strcat(char *dest, char *src);
char **_getenv(const char *name);
int _strcmp(const char *s1,const char *s2);

#endif