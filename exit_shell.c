nclude "shell.h"

/**
 * exit_sh - exits the shell
 * @args: array of arguments
 * Return: void
 */
void exit_sh(char **args)
{
int status = 0;

if (args[1] != NULL)
{
status = _atoi(args[1]);
}
exit(status);
}
