#include "shell.h"

/**
 * print_env - prints the environment
 * @environ: environment variables
 * Return: void
 */
void print_env(char **environ)
{
int i = 0;

while (environ[i] != NULL)
{
write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
write(STDOUT_FILENO, "\n", 1);
i++;
}
}

/**
 * exit_shell - exits the shell with the given status
 * @status: exit status
 * Return: void
 */
void exit_shell(int status)
{
exit(status);
}

/**
 * set_env - sets the environment variable
 * @var: variable name
 * @value: variable value
 * Return: void
 */
void set_env(char *var, char *value)
{
char *new = NULL;
int i = 0;
int j = 0;
int k = 0;
int len = 0;

while (environ[i] != NULL)
{
if (_strncmp(environ[i], var, _strlen(var)) == 0)
{
len = _strlen(environ[i]) + _strlen(value) + 1;
new = malloc(sizeof(char) * len);
if (new == NULL)
{
perror("Error: ");
free(new);
return;
}
while (environ[i][j] != '\0')
{
new[j] = environ[i][j];
j++;
}
new[j] = '=';
j++;
while (value[k] != '\0')
{
new[j] = value[k];
j++;
k++;
}
new[j] = '\0';
environ[i] = new;
return;
}
i++;
}
free(new);
}

/**
 * unset_env - unsets the environment variable
 * @var: variable name
 * Return: void
 */
void unset_env(char *var)
{
int i = 0;
int j = 0;
int k = 0;
int len = 0;
char *new;

while (environ[i] != NULL)
{
if (_strncmp(environ[i], var, _strlen(var)) == 0)
{
len = _strlen(environ[i]);
new = malloc(sizeof(char) * len);
if (new == NULL)
{
perror("Error: ");
return;
}
while (environ[i][j] != '\0')
{
if (environ[i][j] == '=')
{
j++;
break;
}
new[j] = environ[i][j];
j++;
}
while (environ[i][j] != '\0')
{
new[k] = environ[i][j];
j++;
k++;
}
new[k] = '\0';
environ[i] = new;
return;
}
i++;
}
}
