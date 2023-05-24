#include "shell.h"

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: 0 if strings are equal, 1 if not
 */
int _strcmp(char *s1, char *s2)
{
int i = 0;

while (s1[i] != '\0' && s2[i] != '\0')
{
if (s1[i] != s2[i])
return (1);
i++;
}
if (s1[i] != s2[i])
return (1);
return (0);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: string
 * Return: pointer to new string
 */
char *_strdup(const char *str)
{
char *new = NULL;
size_t len = _strlen(str) + 1;

if (str == NULL)
return (NULL);
new = malloc(len);
if (new == NULL)
{
perror("Error: Memory not allocated");
return (NULL);
}
_strcpy(new, str);
return (new);
free(new);
}

/**
 * _atoi - converts a string to an integer
 * @s: string
 * Return: integer
 */
int _atoi(char *s)
{
int i = 0;
int sign = 1;
unsigned int num = 0;

while (s[i] != '\0')
{
if (s[i] == '-')
sign *= -1;
if (s[i] >= '0' && s[i] <= '9')
{
num = num * 10 + (s[i] - '0');
if (s[i + 1] < '0' || s[i + 1] > '9')
break;
}
i++;
}
return (num *sign);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return: pointer to destination string
 */
char *_strcat(char *dest, char *src)
{
int i = 0;
int j = 0;

while (dest[i] != '\0')
i++;
while (src[j] != '\0')
{
dest[i] = src[j];
i++;
j++;
}
dest[i] = '\0';
return (dest);
}

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length of string
 */
int _strlen(const char *s)
{
int i = 0;

while (s[i] != '\0')
i++;
return (i);
}
