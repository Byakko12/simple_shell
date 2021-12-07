#include "shell.h"

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

char *_strcat(char *dest, char *src)
{
    int i = 0, j = 0;

    for (; dest[i] != '\0'; i++)
    {
    }
    for (; src[j] != '\0'; j++)
    {
        dest[i++] = src[j];
    }
    dest[i] = '\0';
    return (dest);
}

char **_token_path(char *path, char *token)
{
    int i = 0;
    char **tokens = NULL;
    char *slash = "/";
    char *string = NULL;

    for (; (tokens[i] = _strtok(path, ":")); path = NULL, i++)
    {
        string = _strcat(slash, token);         // /ls
        tokens[i] = _strcat(tokens[i], string); // /usr/bin
        printf("%s\n", tokens[i]);
        if (tokens[i] == NULL)
        {
            break;
        }
    }
    return (tokens);
}

char **_getenv(const char *name)
{
    int i = 0, dub = 0;
    char **envi = __environ;
    char **str_compare = NULL;
    /* char *env = "PATH";*/

    while (envi[i])
    {
        str_compare = _strtok(envi[i], "=");
        dub = _strcmp(str_compare[i], name);

        if (!dub)
        {
            str_compare = _strtok(NULL, "");
            return (str_compare);
        }
        i++;
    }
    return (NULL);
}

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
