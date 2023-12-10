#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"

/**
 * find_command- Command that finds a path.
 * @command:The command.
 *
 * Return: 0(success)
 */
char* find_command(const char *command) {
    char *path = getenv("PATH");
    char *token = strtok(strdup(path), ":");

    while (token != NULL) {
	    char *executable_path = malloc(strlen(token) + strlen(command) + 2);
        sprintf(executable_path, "%s/%s", token, command);

        if (access(executable_path, X_OK) == 0) {
            free(token);
            return executable_path;
        }

        free(executable_path);
        token = strtok(NULL, ":");
    }

    free(token);
    return NULL;
}
