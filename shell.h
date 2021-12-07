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
int check_coincidence(char* string, char b);
int num_before_delimit(char *string, char *delim, int n);
int count_delimit(char *string, char *delim, int n);
char *_strncpy(char *delim, char *src, int n, int i);
int count_chars_words(char *string, char *delim);
char **_strtok(char *string, char *delim);
char *stat_path(char *, char **argv);
int cd_built_in();
int help_built_in();
int exit_built_in();
char (*built_in(char **argv))(char **tokens);
char *_strcat(char *dest, char *src);
char **_getenv(const char *name);
int _strcmp(const char *s1,const char *s2);

#endif