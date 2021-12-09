#ifndef _HEADER_SHELL_
#define _HEADER_SHELL_

/*libraries*/
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

/*MACROS*/
#define BUFFSIZE 1024
#define out STDOUT_FILENO
#define DELIMIT " \n\t"
/**
 * struct commands - Structure to comparate strings.
 * @comparated: string to compare the data type.
 * @functionStr: Function to make the conversion.
 */
typedef struct commands
{
	char *comparated;
	int (*functionStr)(char **argv, char *string, int n);

} template;

int check_coincidence(char *string, char b);
int num_before_delimit(char *string, char *delim, int n);
int count_delimit(char *string, char *delim, int n);
char *_strncpy(char *delim, char *src, int n, int i);
int count_chars_words(char *string, char *delim);
char **_strtok(char *string, char *delim);
int cd_built_in(char **argv, char *string, int n);
int help_built_in(char **argv, char *string, int n);
int env_built_in(char **argv, char *string, int n);
int exit_built_in(char **argv, char *string, int n);
int (*built_in(char **argv))(char **tokens, char *string, int n);
char *_strcat_memory(char *t_path, char *sls, char *command);
char *_getenv(char *name);
int _strcmp(const char *s1, const char *s2);
int exec_command(char **argv);
void free_all(char **argv, char *str);
void free_arrays(char **array);
char *store_tokens(char **argv);
int _strlen(char *s);
int execut(char *argument, char **tokens);
void free_grid(char **grid, int height);
int validate_main(char **tokens, char *str, int n);
int is_number(char **argv);
int _atoi(char *s);
char *concat_path(char *command, char **p_tokenized);


#endif
