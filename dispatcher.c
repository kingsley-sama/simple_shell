#include "shell.h"
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
void dispatcher(char *str)
{
	int i = 0;
	pid_t id = fork();
	
	char *dest = malloc(sizeof(char) * strlen(str) + 1);
	while (str[i] != '\0' && str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	if (id == 0)
	{
		execlp(dest, dest, (char*)NULL);
	}
	free(dest);
	wait(NULL);
	
}
