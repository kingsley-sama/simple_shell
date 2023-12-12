#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
#include <sys/wait.h>
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

		if (execv(prog_path, command) == -1)
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
