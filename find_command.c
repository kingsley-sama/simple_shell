#include "shell.h"

/**
 * path_cmd -  Search In $PATH for executable command
 * @cmd: Parsed input.
 *
 * Return: 0 on success or  1 on failure  0.
 */
int path_cmd(char **cmd)
{
	char *path, *value, *command_path;
	struct stat buf;

	path = get_env("PATH");
	value = str_tok(path, ":");
	while (value != NULL)
	{
	command_path = build(*cmd, value);
	if (stat(command_path, &buf) == 0)
	{
	*cmd = str_dup(command_path);
	free(command_path);
	free(path);
	return (0);
	}
	free(command_path);
	value = str_tok(NULL, ":");
	}
	free(path);
	free(value);
	return (1);
}

/**
 * build - Build command
 * @token: Executable command
 * @value: Directory conatining Command
 *
 * Return: Parsed full path of command or NULL if failed
 */
char *build(char *token, char *value)
{
	char *command_line;
	size_t len;

	len = str_len(value) + str_len(token) + 2;
	command_line = malloc(sizeof(char) * len);
	if (command_line == NULL)
	{
	free(command_line);
	return (NULL);
	}

	memset(command_line, 0, len);

	command_line = str_cat(command_line, value);
	command_line = str_cat(command_line, "/");
	command_line = str_cat(command_line, token);

	return (command_line);
}

/**
 * get_env - Gets the value of environment variable by name
 * @name: Environment variable name
 *
 * Return: The value of the environment variable or NULL if failed
 */
char *get_env(char *name)
{
	size_t name_len, value_len;
	char *value;
	int i, j, k;

	name_len = str_len(name);
	for (i = 0 ; environ[i]; i++)
	{
	if (strn_cmp(name, environ[i], name_len) == 0)
	{
	value_len = str_len(environ[i]) - name_len;
	value = malloc(sizeof(char) * value_len);
	if (!value)
	{
	free(value);
	perror("unable to alloc");
	return (NULL);
	}

	j = 0;
	for (k = name_len + 1; environ[i][k]; k++, j++)
	{
	value[j] = environ[i][k];
	}
	value[j] = '\0';

	return (value);
	}
	}
	return (NULL);
}
