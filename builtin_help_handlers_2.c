#include "shell.h"

/**
 * help_env - Displays information on the shell by builtin command 'env'
 *
 * Return:Void.
 */
void help_env(void)
{
	char *msg = "env: env\n\tPrints the current environment.\n";

	write(STDOUT_FILENO, msg, str_len(msg));
}

/**
 * help_setenv - Displays information on the shell by builtin command 'setenv'
 *
 * Return:Void
 */
void help_setenv(void)
{
	char *msg = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";

	write(STDOUT_FILENO, msg, str_len(msg));
	msg = "environment variable, or modifies an existing one.\n\n";
	write(STDOUT_FILENO, msg, str_len(msg));
	msg = "\tUpon failure, prints a message to stderr.\n";
	write(STDOUT_FILENO, msg, str_len(msg));
}

/**
 * help_unsetenv - Displays information on the shellby builtin command
 * 'unsetenv'
 *
 * Return:Void
 */
void help_unsetenv(void)
{
	char *msg = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";

	write(STDOUT_FILENO, msg, str_len(msg));
	msg = "environmental variable.\n\n\tUpon failure, prints a ";
	write(STDOUT_FILENO, msg, str_len(msg));
	msg = "message to stderr.\n";
	write(STDOUT_FILENO, msg, str_len(msg));
}

/**
 * display_help - display help for builtin commands
 * @cmd: parsed command
 * @st: Status of last command executed
 *
 * Return: 0 Success
 */
int display_help(char **cmd, __attribute__((unused))int st)
{
	if (!cmd[1])
		help_all();
	else if (str_cmp(cmd[1], "alias") == 0)
		help_alias();
	else if (str_cmp(cmd[1], "cd") == 0)
		help_cd();
	else if (str_cmp(cmd[1], "exit") == 0)
		help_exit();
	else if (str_cmp(cmd[1], "env") == 0)
		help_env();
	else if (str_cmp(cmd[1], "setenv") == 0)
		help_setenv();
	else if (str_cmp(cmd[1], "unsetenv") == 0)
		help_unsetenv();
	else if (str_cmp(cmd[1], "help") == 0)
		help_help();
	return (0);
}
