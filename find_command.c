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
	char *path_copy;

	if (path == NULL)
	return (NULL);

	printf("%s\n", path);

	path_copy = strdup(path);
	if (path_copy == NULL)
	{
	perror("Memory allocation failed");
	return (NULL);
	}

	token = strtok(path_copy, ":");
	exec_path = (char *)malloc(strlen(token) + strlen(command) + 2);

	if (exec_path == NULL)
	{
	perror("Memory allocation failed");
	free(path_copy);
	return (NULL);
	}

	while (token != NULL)
	{
	strcpy(exec_path, token);
	strcat(exec_path, "/");
	strcat(exec_path, command);

	if (access(exec_path, X_OK) == 0)
	{
	printf("%s", exec_path);
	free(path_copy);
	printf("this is :%s\n", exec_path);
	return (exec_path);
	}

	token = strtok(NULL, ":");
	}

	free(exec_path);
	free(path_copy);
	return (NULL);
}
