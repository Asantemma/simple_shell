#include "shell.h"

/**
 * cd_home - changes directory to home
 * Return: void
 */
void cd_home(void)
{
char *home = _getenv("HOME");
char *pwd = _getenv("PWD");
char *newpwd;

if (chdir(home) == -1)
{
perror("hsh");
}
else
{
newpwd = malloc(_strlen(home) + 6);
_strncpy(newpwd, "PWD=", 4);
_strncat(newpwd, home, _strlen(home) + 1);
set_env("PWD", home);
set_env("OLDPWD", pwd);
free(newpwd);
}
}

/**
 * cd_path - changes directory to path
 * @path: arguments
 * Return: void
 */
void cd_path(char *path)
{
char *token;

token = _strntok(path, " ", _strlen(path));
while (token != NULL)
{
path = malloc(_strlen(token) + 1);
_strncpy(path, token, _strlen(token) + 1);
token = strtok(NULL, " ");
}
if (chdir(path) == -1)
{
perror("hsh");
}
else
{
set_env("OLDPWD", _getenv("PWD"));
}
}

/**
 * cd_prev - changes directory to previous
 * Return: void
 */
void cd_prev(void)
{
char *oldpwd = _getenv("OLDPWD");
int ret;

if (oldpwd == NULL)
{
write(STDERR_FILENO, "hsh: cd: OLDPWD not set\n", 24);
return;
}
ret = chdir(oldpwd);
if (ret == -1)
{
perror("hsh");
}
else
{
set_env("OLDPWD", _getenv("PWD"));
set_env("PWD", oldpwd);
}
}


/**
 * cd_run - runs the cd command
 * @path: arguments
 * Return: void
 */
void cd_run(char *path)
{
if (_strncmp(path, "~", 1) == 0 || _strcmp(path, "--") == 0)
{
cd_home();
}
if (_strncmp(path, "-", 1) == 0)
{
cd_prev();
}
else
{
cd_path(path);
}
}
