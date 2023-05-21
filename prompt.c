#include "shell.h"

/**
 * show_prompt - displays the prompt
 * Return: void
 */
void show_prompt(void)
{
/* Displays a simple prompt and waits for input */
write(STDOUT_FILENO, "$ ", 2);
}
