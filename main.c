#include "shell.h"

/**
 * main - entry point
 * Return: 0 if successfull
 */
int main(void)
{
char buffer[MAX_LINE];
char *args[MAX_ARGS];
int status = 1;
ssize_t bytes_read = 0;

while (status)
{
if (isatty(STDIN_FILENO))
show_prompt();
bytes_read = read(STDIN_FILENO, buffer, MAX_LINE);
if (bytes_read == -1)
{
perror("Error");
exit(1);
}
if (bytes_read == 0)
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n", 1);
exit(0);
}
buffer[bytes_read - 1] = '\0';
parse_input(buffer, args);
if (args[0] == NULL)
continue;
if (builtins(args, environ))
continue;
exec_command(args, environ);
}
return (0);
}

/**
 * builtins - checks for builtins
 * @args: arguments
 * @env: environment variables
 * Return: 1 if builtin, 0 if not
 */
int builtins(char **args, char **env)
{
if (_strcmp(args[0], "exit") == 0)
exit_sh(args);
if (_strcmp(args[0], "env") == 0)
print_env(env);
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
