#include "shell.h"
/**
 * read_file - Reads commands from the argument File
 * @file: File containing commands
 * @argv: Arguments passed
 * Return: -1 or 0
 */
void read_file(char *file, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t s_len = 0;
	int i = 0;

	fp = fopen(file, "r");
	if (fp == NULL)
	{
		error_file(argv, i);
		exit(127);
	}
	while ((getline(&line, &s_len, fp)) != -1)
	{
		i++;
		treat_file(line, i, fp, argv);
	}
	if (line)
		free(line);
	fclose(fp);
	exit(0);
}

/**
 * treat_file - Parse commands and handle their execution
 * @line: Line from file
 * @i: Error ier
 * @fp: File descriptor
 * @argv: Command line arguments
 */
void treat_file(char *line, int i, FILE *fp, char **argv)
{
	char **command_line;
	int stat = 0;

	command_line = parse_cmd(line);
	if (strn_cmp(command_line[0], "exit", 4) == 0)
		exit_bull(command_line, line, fp);
	else if (check_builtin(command_line) == 0)
	{
		stat = handle_builtin(command_line, stat);
		free(command_line);
	}
	else
	{
		stat = check_cmd(command_line, line, i, argv);
		free(command_line);
	}
}

/**
 * exit_bull - Exit status handler for file input
 * @line: Line from a file
 * @cmd: Parsed command
 * @fd: File Descriptor
 */
void exit_bull(char **cmd, char *line, FILE *fd)
{
	int status;
	int i = 0;

	if (cmd[i] == NULL)
	{
		free(line);
		free(cmd);
		fclose(fd);
		exit(errno);
	}
	while (cmd[1][i])
	{
		if (is_alpha(cmd[1][i++]) < 0)
			perror("Illegal number");
	}
	status = ato_i(cmd[1]);
	free(line);
	free(cmd);
	fclose(fd);
	exit(status);
}
