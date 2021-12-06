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

int check_coincidence(char* string, char b);
char *_strncpy(char *dest, char *src, int n , int initial);
int num_before_delimit(char *string, char *delim, int n);
int count_delimit(char *string, char *delim, int n);

#endif