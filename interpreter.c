#include "shell.h"

/**
 * parse_input - parses the input from the user
 * @buffer: buffer to store the input
 * @args: array of arguments
 * Return: void
 */
void parse_input(char *buffer, char **args)
{
int i = 0;
char *token;

token = strtok(buffer, " \n");
while (token != NULL)
{
args[i] = token;
token = strtok(NULL, " \n");
i++;
}
args[i] = NULL;
}

/**
 * command_AR - runs if the command is an absolute or relative path
 * @args: array of arguments
 * @env: environment variables
 * Return: void
 */
void command_AR(char **args, char **env)
{
pid_t pid;

/* Fork a child process */
pid = fork();
if (pid == 0)
{
/* Child process */
if (execve(args[0], args, env) == -1)
{
perror("Error");
}
}
else if (pid < 0)
{
/* Error forking */
perror("Error");
}
else
{
/* Parent process */
waitpid(pid, NULL, 0);
}
}

/**
 * path_check - checks if the command is in the PATH
 * checks in PATH
 * @args: array of arguments
 * @env: environment variables
 * Return: void
 */
void path_check(char **args, char **env)
{
char *path;
char *command = NULL;
char *path_array[MAX_PATH];
char *token;
struct stat st;
int i = 0;

path = _getenv("PATH");
token = strtok(path, ":");
while (token != NULL)
{
path_array[i] = malloc(sizeof(char) * MAX_PATH);
if (path_array[i] == NULL)
{
perror("Error");
free(path_array[i]);
return;
}
_strncpy(path_array[i], token, MAX_PATH);
path_array[MAX_PATH - 1] = '\0';

command = _strncat(path_array[i], "/", 1);
command = _strncat(command, args[0], _strlen(args[0]));

/* Check if the command exists */
if (stat(command, &st) == 0)
{
i = 0;
execute(command, args, env);
free(path_array[i]);
return;
}
token = strtok(NULL, ":");
}
perror("Error");
free(path_array[i]);
return;
}

/**
 * execute - executes the command with the arguments
 * @command: command to execute
 * @args: array of arguments
 * @env: environment variables
 * Return: void
 */
void execute(char *command, char **args, char **env)
{
pid_t pid;

pid = fork();
if (pid == 0)
{
if (execve(command, args, env) == -1)
{
perror("Error");
}
}
else if (pid < 0)
{
perror("Error");
}
else
{
waitpid(pid, NULL, 0);
}
}

/**
 * exec_command - executes the command with the arguments
 * checks in PATH
 * @args: array of arguments
 * @env: environment variables
 * Return: void
 */
void exec_command(char **args, char **env)
{
if (args[0] == NULL)
return;
if (_strcmp(args[0], "exit") == 0)
{
exit_sh(args);
}
if (_strcmp(args[0], "env") == 0)
{
print_env(env);
return;
}
if (_strcmp(args[0], "setenv") == 0)
{
set_env(args[1], args[2]);
return;
}
if (_strcmp(args[0], "unsetenv") == 0)
{
unset_env(args[1]);
return;
}
if (_strcmp(args[0], "cd") == 0 && args[1] == NULL)
{
cd_home();
return;
}
if (_strcmp(args[0], "cd") == 0 && args[1] != NULL)
{
cd_run(args[1]);
return;
}
if (args[0][0] == '/' || args[0][0] == '.')
{
command_AR(args, env);
}
else
{
path_check(args, env);
}
}
