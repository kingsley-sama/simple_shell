#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * find_command - Command that finds a path.
 * @command: The command.
 * Return: Full path to the command if found, NULL otherwise.
 */
char *find_command(const char *command)
{
	char *token;
	char *exec_path;
	char *path = getenv("PATH");

	if (path == NULL)
		return NULL;
	token = strtok(strdup(path), ":");
	exec_path = malloc(strlen(token) + strlen(command) + 2);
	while (token != NULL)
	{
		str_cpy(exec_path, token);
		str_cat(exec_path, "/");
		str_cat(exec_path, command);
		if (access(exec_path, X_OK) == 0) {
			free(token);
			return exec_path;
		}
		token = strtok(NULL, ":");
	}
	free(exec_path);
	return NULL;
}
