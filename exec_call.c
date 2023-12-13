#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
#include <sys/wait.h>

/**
 * exec_command- Execute commands.
 * @command: A pointer that points to the address of the command.
 *
 * Return:Void
 */
void exec_command(char **command)
{
	char *prog_path;

	prog_path = find_command(command[0]);
	if (prog_path == NULL)
	return;
	pid_t pid = fork();
	if (pid == -1)
	{
	perror("fork");
	exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
	if (execve(prog_path, command, NULL) == -1)
	{
	perror("execv");
	exit(EXIT_FAILURE);
	}
	}
	else
	{
	int status;
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
	printf("Command exited with status %d\n", WEXITSTATUS(status));
	}
	free(prog_path);
}
