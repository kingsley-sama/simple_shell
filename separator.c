#include "shell.h"

/**
 * separator - Separates command recieved from stdin by ;
 * @input: String gathered from stdin
 * Return: Parsed strings to be used as commands
 */
char **separator(char *input)
{
	char **commands;
	char *command;
	int i;
	int buffsize = BUFSIZE;

	if (input[0] == ' ' && input[str_len(input)] == ' ')
		exit(0);
	if (input == NULL)
		return (NULL);
	commands = malloc(sizeof(char *) * buffsize);
	if (!commands)
	{
		free(commands);
		perror("hsh");
		return (NULL);
	}
	command = str_tok(input, ";&");
	for (i = 0; command; i++)
	{
		commands[i] = command;
		command = str_tok(NULL, ";&");
	}
	commands[i] = NULL;

	return (commands);
}
