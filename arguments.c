#include "shell.h"

/**
 * parse_args - parses the arguments from the user
 * @buffer: buffer to store the input
 * @args: array of arguments
 * Return: number of arguments
 */
int parse_args(char *buffer, char **args)
{
int i = 0;
char *token;

token = strtok(buffer, " \t\n");
while (token != NULL)
{
args[i] = malloc(sizeof(char) * MAX_LINE);
if (args[i] == NULL)
{
perror("Error");
for (i = 0; args[i] != NULL; i++)
free(args[i]);
return (0);
}
_strncpy(args[i], token, MAX_LINE);
token = strtok(NULL, " ");
i++;
}
args[i] = NULL;
return (i);
}
