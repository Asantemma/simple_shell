#include "shell.h"

/**
 * _get_token - gets the token
 * @token: token
 * @delim: delimiter
 * @n: number of bytes to tokenize
 * Return: pointer to the tokenized string
 */
char *_get_token(char *token, const char *delim, int n)
{
int i = 0;
int j = 0;
int k = 0;
char *new;

i = 0;
while (token[i] != '\0' && i < n)
{
j = 0;
while (delim[j] != '\0')
{
if (token[i] == delim[j])
{
new = malloc(sizeof(char) * (i + 1));
if (new == NULL)
{
perror("Error: ");
return (NULL);
}
new[i] = '\0';
return (new);
}
j++;
}
i++;
}
new = malloc(sizeof(char) * (i + 1));
if (new == NULL)
{
perror("Error: ");
return (NULL);
}
for (k = 0; k < i; k++)
new[k] = token[k];
new[k] = '\0';
token = token + i;
return (new);
}
