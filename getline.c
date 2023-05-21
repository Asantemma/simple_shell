#include "shell.h"

/**
 * _getline - reads an entire line from a file descriptor
 * @fd: file descriptor
 * Return: pointer to the line
 */
char *_getline(const int fd)
{
char *line = NULL;
char buffer[1024];
int i = 0, j = 0, k = 0, n = 0;

while ((n = read(fd, buffer, 1024)) > 0)
{
for (i = 0; i < n; i++)
{
if (buffer[i] == '\n')
{
line = malloc(sizeof(char) * (j + 1));
if (line == NULL)
{
perror("Error: malloc failed");
return (NULL);
}
for (k = 0; k < j; k++)
line[k] = buffer[k];
line[k] = '\0';
return (line);
}
j++;
}
}
return (line);
}
