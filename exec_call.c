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

	prog_path = command[0];
	if (command[1] != NULL)
	{
		print_str("./shell: No such file or directory");
		exit(EXIT_FAILURE);
	}
	if (prog_path == NULL)
	{
		return (-1);
	}
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	else if (pid == 0)
	{
		if (execve(prog_path, command, NULL) == -1)
		{
			print_str("./shell: No such file or directory");
			exit(EXIT_FAILURE);
		}

	}
	else
		waitpid(pid, &status, 0);

	free(prog_path);
	return (0);
}
