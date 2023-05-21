#include "shell.h"

/**
 * _strncat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * @n: number of bytes to concatenate
 * Return: pointer to destination string
 */
char *_strncat(char *dest, char *src, int n)
{
int i = 0;
int j = 0;

while (dest[i] != '\0')
i++;
while (src[j] != '\0' && j < n)
{
dest[i] = src[j];
i++;
j++;
}
dest[i] = '\0';
return (dest);
}

/**
 * _strntok - tokenizes a string
 * @str: string
 * @delim: delimiter
 * @n: number of bytes to tokenize
 * Return: pointer to the tokenized string
 */
char *_strntok(char *str, const char *delim, int n)
{
static char *token;
int i = 0;
int j = 0;
char *new;

if (str != NULL)
token = str;
while (token[i] != '\0' && i < n)
{
j = 0;
while (delim[j] != '\0')
{
if (token[i] == delim[j])
{
token = token + i + 1;
i = -1;
break;
}
j++;
}
i++;
}
if (token[0] == '\0')
return (NULL);
new = _get_token(token, delim, n);
return (new);
}
