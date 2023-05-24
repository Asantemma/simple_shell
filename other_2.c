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

/**
 * _strchr - locates a character in a string
 * @s: string
 * @c: character to locate
 * Return: pointer to the first occurrence of the character
 */
char *_strchr(char *s, char c)
{
int i = 0;

while (s[i] != '\0')
{
if (s[i] == c)
return (s + i);
i++;
}
if (s[i] == c)
return (s + i);
return (NULL);
}

/**
 * itoa - converts an integer to a string
 * @num: integer to convert
 * Return: pointer to the converted string
 */
char *itoa(int num)
{
int i = 0;
int j = 0;
char *str = malloc(sizeof(char) * 1024);

if (str == NULL)
{
perror("Error");
return (NULL);
}
if (num == 0)
{
str[i] = '0';
str[i + 1] = '\0';
return (str);
}
while (num != 0)
{
str[i] = (num % 10) + '0';
num = num / 10;
i++;
}
str[i] = '\0';
i--;
while (j < i)
{
str[j] = str[j] + str[i];
str[i] = str[j] - str[i];
str[j] = str[j] - str[i];
j++;
i--;
}
return (str);
}
