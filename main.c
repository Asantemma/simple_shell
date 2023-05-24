#include "shell.h"

/**
 * main - entry point
 * Return: 0 if successfull
 */
int main(void)
{
char buffer[MAX_LINE];
char *args[MAX_ARGS];
char *commands[MAX_ARGS];
int status = 1;
int num_commands= 0;
ssize_t bytes_read = 0;

while (status)
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "$ ", 2);
bytes_read = read(STDIN_FILENO, buffer, MAX_LINE);
if (bytes_read == 0)
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n", 1);
exit(0);
}
if (bytes_read == -1)
{
perror("Error");
exit(1);
}
buffer[bytes_read - 1] = '\0';
num_commands = parse_input(buffer, commands);
args_handler(num_commands, commands, args, environ);
}
return (0);
}

/**
 * args_handler - handles arguments
 * @commands_count: number of commands
 * @commands: commands
 * @args: arguments
 * @env: environment variables
 * Return: 0 if successful
 */
int args_handler(int commands_count, char **commands,
char **args, char **env)
{
int i, j, num_args = 0;

for (i = 0; i < commands_count; i++)
{
num_args = parse_args(commands[i], args);
if (num_args == 0)
{
for (j = 0; args[j] != NULL; j++)
free(args[j]);
continue;
}
if (builtins(args) == 1)
{
for (j = 0; args[j] != NULL; j++)
free(args[j]);
continue;
}
if (access(args[0], F_OK) == 0)
command_AR(args, env);
else
path_check(args, env);
for (j = 0; args[j] != NULL; j++)
free(args[j]);
}
return (0);
}

/**
 * builtins - checks for builtins
 * @args: arguments
 * @env: environment variables
 * Return: 1 if builtin, 0 if not
 */
int builtins(char **args)
{
if (_strcmp(args[0], "exit") == 0)
exit_sh(args);
if (_strcmp(args[0], "env") == 0)
print_env(args);
if (_strcmp(args[0], "setenv") == 0)
set_env(args[1], args[2]);
if (_strcmp(args[0], "unsetenv") == 0)
unset_env(args[1]);
if (_strcmp(args[0], "cd") == 0)
{
if (args[1] == NULL)
cd_home();
else if (_strcmp(args[1], "-") == 0)
cd_prev();
else
cd_run(args[1]);
}
if (_strcmp(args[0], "help") == 0)
{
welcome();
return (1);
}
return (0);
}
