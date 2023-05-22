#include "shell.h"

/**
 * welcome - prints welcome message
 * Return: void
 */
void welcome(void)
{
write(STDOUT_FILENO, "===================================", 36);
write(STDOUT_FILENO, "\n", 1);
write(STDOUT_FILENO, "===================================", 36);
write(STDOUT_FILENO, "\n", 1);
write(STDOUT_FILENO, "Welcome to Our Simple Shell", 28);
write(STDOUT_FILENO, "\n", 1);
write(STDOUT_FILENO, "===================================", 36);
write(STDOUT_FILENO, "\n", 1);
write(STDOUT_FILENO, "WRITTEN IN C BY: Jesse and Emmanuel", 36);
write(STDOUT_FILENO, "\n", 1);
write(STDOUT_FILENO, "===================================", 36);
write(STDOUT_FILENO, "\n", 1);
write(STDOUT_FILENO, "===================================", 36);
write(STDOUT_FILENO, "\n", 1);
write(STDOUT_FILENO, "Type 'exit' to exit.", 21);
write(STDOUT_FILENO, "\n", 1);
write(STDOUT_FILENO, "===================================", 36);
write(STDOUT_FILENO, "\n", 1);
}
