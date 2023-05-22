#include "shell.h"

/**
 * is_var - checks if the command is a variable
 * @args: array of arguments
 * @env: environment variables
 * Return: 1 if it is a variable, 0 if not
 */
int is_var(char **args, char **env)
{
    char *var;
    char *value;
    char *token;
    char *path;
    char *command;
    char **args2;
    int i;

    if (args[0][0] == '$')
    {
        var = malloc(_strlen(args[0]) + 1);
        _strncpy(var, args[0] + 1, _strlen(args[0]));
        value = _getenv(var);
        if (value == NULL)
        {
            free(var);
            return (0);
        }
        free(args[0]);
        args[0] = malloc(_strlen(value) + 1);
        _strncpy(args[0], value, _strlen(value) + 1);
        free(var);
        return (1);
    }
    return (0);
}

/**
 * get_var - gets the value of the variable
 * @args: array of arguments
 * @env: environment variables
 * Return: void
 */
void get_var(char **args, char **env)
{
    char *var;
    char *value;
    char *token;
    char *path;
    char *command;
    char **args2;
    int i;

    if (args[0][0] == '$')
    {
        var = malloc(_strlen(args[0]) + 1);
        _strncpy(var, args[0] + 1, _strlen(args[0]));
        value = _getenv(var);
        if (value == NULL)
        {
            free(var);
            return;
        }
        free(args[0]);
        args[0] = malloc(_strlen(value) + 1);
        _strncpy(args[0], value, _strlen(value) + 1);
        free(var);
    }
}