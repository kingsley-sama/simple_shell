#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * find_command - Command that finds a path.
 * @command: The command.
 * Return: Full path to the command if found, NULL otherwise.
 */
char *find_command(const char *command)
{
	char *token, *new_exec_path, *exec_path, *path_copy, *path = getenv("PATH");
	size_t exec_path_size;

	if (command[0] == '/')
	{
		if (access(command, X_OK) == 0)
			return (strdup(command));
		else
			return (NULL);
	}
	if (path == NULL)
		return (NULL);
	path_copy = strdup(path);
	if (path_copy == NULL)
		return (NULL);
	token = strtok(path_copy, ":");
	exec_path = NULL;
	while (token != NULL)
	{
		exec_path_size = strlen(token) + strlen(command) + 2;
		new_exec_path = (char *)realloc(exec_path, exec_path_size);
		exec_path = new_exec_path;
		strcpy(exec_path, token);
		strcat(exec_path, "/");
		strcat(exec_path, command);
		if (access(exec_path, X_OK) == 0)
		{
			free(path_copy);
			return (exec_path);
		}
		token = strtok(NULL, ":");
	}
	free(exec_path);
	free(path_copy);
	return (NULL);
}
