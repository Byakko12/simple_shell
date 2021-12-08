#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: array of strings
 * Return: return length
 */
int _strlen(char *s)
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
        ;
    return (i);
}

/**
 * *_strcmp - compares two strings.
 * @s1: String number 1
 * @s2: String number 2
 * Return: return positive if s1 is greater than s2
 * negatives if is less or 0 if is equal
 */
int _strcmp(const char *s1,const char *s2)
{
    int i = 0, temp;

    for (; s1[i] != '\0'; i++)
    {
        if (s1[i] == s2[i])
        {
            temp = 0;
        }
        else
        {
            temp = (s1[i] - s2[i]);
            break;
        }
    }
    return (temp);
}

/**
 * *_strncat - concatenates two strings and size
 * @dest: Array buffer
 * @src: Array to append
 * @n: size of array
 * Return: dest with two strings concat
 */
char *_strcat_memory(char *dest, char *src)
{
    int i, j = 0;
    int count = _strlen(dest) + _strlen(src);
    char *string = malloc(sizeof(char *) * count + 1);
    char *new = NULL;

    if (string == NULL)
    {
        return (NULL);
    }

    for (i = 0; dest[i] != '\0'; i++)
    {
        string[i] = dest[i];
    }
    for (i; i <= count; i++, j++)
    {
        string[i] = src[j];
    }
    string[i] = '\0';
    return (string);
}


char *_getenv(const char *name)
{
    int i = 0, dub = 0;
    char **envi = __environ;
    char **strings = NULL;
    /* char *env = "PATH";*/

    while (envi[i])
    {
        strings = _strtok(envi[i], "=");
        dub = _strcmp(strings[0], name);

        if (!dub)
        {
            return (strings[1]);
        }
        i++;
    }
    return (NULL);
}
/*
int main()
{
    int i = 0;
    char *p = "PATH";
    char **path = NULL;
    char **paaath = NULL;
    path = _getenv(p);

    printf("%s", p);

    paaath = _token_path(path, "ls");

    for (i = 0; paaath[i]; i++)
    {
        printf("%s", paaath[i]);
    }
    return (0);
}
*/
