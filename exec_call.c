#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
#include <sys/wait.h>
/**
 * exec_command- Execute commands.
 * @command: A pointer that points to the address of the command.
 * Return: process status
 */
int exec_command(char **command)
{
	char *prog_path;
	pid_t pid;
	int status;

	prog_path = find_command(command[0]);
	if (prog_path == NULL)
	{
		print_str(command[0]);
		print_str(": command not found");
		return (-1);
	}
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	else if (pid == 0)
	{
		if (execve(prog_path, command, NULL) == -1)
			exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, &status, 0);

	free(prog_path);
	return (0);
}
