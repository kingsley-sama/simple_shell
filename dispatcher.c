#include "shell.h"
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
void dispatcher(char *str)
{
	int i = 0;
	pid_t id = fork();
	if (id == 0)
	{
		execlp(str, "ls", (char *)NULL);
	}

	wait(0);
	
}
