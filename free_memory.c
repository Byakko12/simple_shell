#include "shell.h"

/**
 * free_arrays - free memory of the array
 * @array: double pointer to array char variable
 */
void free_arrays(char **array)
{
	if (array && *array)
	{
		free_arrays(array + 1);
		free(*array);
	}
}

/**
 * freestr - free memory of strings data
 * @argv: double pointer to string char variable
 * @str: pointer to string char variable
 */
void free_all(char **argv, char *str)
{
	free_arrays(argv);
	free(argv);
	free(str);
}