#include "shell.h"

/**
 * print_error - Displays error message
 * @input: Input recieved from user
 * @counter: Count of shell loop
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 *
 * Return:Void.
 */

void print_error(char *input, int counter, char **argv)
{
	char *a;

	print_str(argv[0]);
	print_str(": ");
	a = ito_a(counter);
	print_str(a);
	free(a);
	print_str(": ");
	print_str(input);
	print_str(": not found\n");
}

/**
 *  _prerror - Prints custom Error
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * @c: Error Count
 * @cmd: Array of parsed command strings
 *
 * Return:Void.
 */

void _prerror(char **argv, int c, char **cmd)
{
	char *error = ito_a(c);

	print_str(argv[0]);
	print_str(": ");
	print_str(error);
	print_str(": ");
	print_str(cmd[0]);
	print_str(": Illegal number: ");
	print_str(cmd[1]);
	print_str("\n");
	free(error);
}

/**
 * error_file - Prints custom Error
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * @c: Error Count
 *
 * Return:Void
 */
void error_file(char **argv, int c)
{
	char *b = ito_a(c);

	print_str(argv[0]);
	print_str(": ");
	print_str(b);
	print_str(": Can't open ");
	print_str(argv[1]);
	print_str("\n");
	free(b);
}
