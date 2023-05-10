# Simple shell in C

Implementation of Unix Command line interpreter

A project by Emmanuel Asante <asantemma7@gmail.com> and Jesse Otu <chibuzorotu98@gmail.com>

## Description

This is a simple shell that can execute commands and some built-in commands. It can also execute commands with arguments and options.

## Usage

To run the shell, compile all the files in the repository and run the executable file. The shell will prompt you to enter a command. Enter a command and press enter to execute it. To exit the shell, enter the command `exit`.

## Built-in commands

The shell has the following built-in commands:

* `exit` - Exits the shell
* `env` - Prints the current environment
* `cd` - Changes the current directory
* `setenv` - Sets an environment variable
* `unsetenv` - Unsets an environment variable
* `help` - Prints the help message

## Functions

This is a table of all the custom functions used in the shell:

| Function name | Description | File |
| ------------- | ----------- | ---- |
| `main` | The entry point of the shell | `shell.c` |
| `welcome` | Prints the welcome message | `welcome.c` |
| `show_prompt` | Prints the prompt | `prompt.c` |
| `read_input` | Reads the input from the user | `prompt.c` |
| `parse_input` | Parses the input into tokens | `interpreter.c` |
| `exec_command` | Executes the command | `interpreter.c` |
| `command_AR` | Executes a command if it is an absolute or relative path | `interpreter.c` |
| `path_run` | checks if a command is in the PATH | `interpreter.c` |
| `execute` | Executes a command | `interpreter.c` |
| `exec_command` | Executes a command with arguments | `interpreter.c` |
| `cd_home` | Changes the current directory to the home directory | `cd_functions.c` |
| `cd_prev` | Changes the current directory to the previous directory | `cd_functions.c` |
| `cd_path` | Changes the current directory to a specified directory | `cd_functions.c` |
| `cd_run` | Changes the current directory | `cd_functions.c` |
| `print_env` | Prints the current environment | `builtin.c` |
| `set_env` | Sets an environment variable | `builtin.c` |
| `unset_env` | Unsets an environment variable | `builtin.c` |
| `exit_sh` | Exits the shell | `exit_shell.c` |
| `_get_token` | Gets the next token from a string | `get_token.c` |
