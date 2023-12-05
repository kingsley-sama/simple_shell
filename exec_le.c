#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 *exec_le - starts a child process
 *@path: path variable
 *@arguments: arguments
 *@envp: environment
 *Return: 0 if success
 */
int exec_le(const char *path, char *const arguments[], char *const envp[])
{
	if (envp == NULL)
	{
		envp = __environ;
	}
	if (execve(path, arguments, envp) == -1)
	{
		perror("execve");
		return -1;
	}
	return (-1);
}
