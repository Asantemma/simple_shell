#include "shell.h"

/**
 * _strncmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * @n: number of bytes to compare
 * Return: 0 if strings are equal, 1 if not
 */
int _strncmp(char *s1, char *s2, int n)
{
int i = 0;

while (s1[i] != '\0' && s2[i] != '\0' && i < n)
{
if (s1[i] != s2[i])
return (1);
i++;
}
if (s1[i] != s2[i] && i < n)
return (1);
return (0);
}

/**
 * _getenv - gets the value of an environment variable
 * @name: name of the environment variable
 * Return: value of the environment variable
 */
char *_getenv(char *name)
{
int i = 0;
char *env_var;
char *env_value = NULL;
size_t len;

len = _strlen(name);

while (environ[i] != NULL)
{
env_var = _strdup(environ[i]);
if (_strncmp(env_var, name, len) == 0 && env_var[len] == '=')
{
env_value = env_var + len + 1;
return (env_value);
}
free(env_var);
i++;
}
return (NULL);
}

/**
 * _strtok - tokenizes a string
 * @str: string
 * @delim: delimiter
 * Return: pointer to the tokenized string
 */
char *_strtok(char *str, const char *delim)
{
static char *save;
char *token;
int i = 0, j = 0;

if (str == NULL)
str = save;
while (str[i] != '\0')
{
while (delim[j] != '\0')
{
if (str[i] == delim[j])
{
str[i] = '\0';
save = &str[i + 1];
return (str);
}
j++;
}
j = 0;
i++;
}
if (str[i] == '\0')
{
save = &str[i];
return (str);
}
token = NULL;
return (token);
}

/**
 * _strncpy - copies a string
 * @dest: destination string
 * @src: source string
 * @n: number of bytes to copy
 * Return: pointer to the destination string
 */
char *_strncpy(char *dest, char *src, int n)
{
int i = 0;

while (src[i] != '\0' && i < n)
{
dest[i] = src[i];
i++;
}
while (i < n)
{
dest[i] = '\0';
i++;
}
return (dest);
}

/**
 * _strcpy - copies a string
 * @dest: destination string
 * @src: source string
 * Return: pointer to the destination string
 */
char *_strcpy(char *dest, const char *src)
{
int i = 0;

while (src[i] != '\0')
{
dest[i] = src[i];
i++;
}
dest[i] = '\0';
return (dest);
}
