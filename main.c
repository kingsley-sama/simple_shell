#include "shell.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define EXIT_STRING "exit"

int main(int argc, char *argv[])
{
    // Check if the shell is running in non-interactive mode
    int is_interactive = isatty(STDIN_FILENO);

    do {
        char *input = NULL;
        ssize_t getline_val;
        size_t input_size = 0;

        // Print prompt only if running interactively
        if (is_interactive) {
            print_str("($)");
        }

        // Read input from the user or standard input
        getline_val = getline(&input, &input_size, stdin);

        if (getline_val == -1 || strcmp(input, EXIT_STRING) == 0) {
            // Handle getline error or exit command
            if (is_interactive) {
                if (getline_val == -1) {
                    putchar('\n');
                }
            }
            break;
        }

        // Remove newline character from the input
        if (strlen(input) > 0 && input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        }

        // Execute the command
        call_command(input);

        free(input);

        // Print a newline if running interactively
        if (is_interactive) {
            putchar('\n');
        }
    } while (is_interactive);  // Continue the loop only if running interactively

    return 0;
}

/* #include "shell.h" */
/* #include <stddef.h> */
/* #include <stdio.h> */
/* #include <stdlib.h> */
/* #include <string.h> */
/* #include <unistd.h> */
/* /\** */
/*  * main - HSH entry point. */
/*  * @argc: Number of command line argument. */
/*  *@argv: Argument vector. */
/*  * Return: Exit status. */
/*  *\/ */
/* int main(void) */
/* { */
/* 	do { */
/* 		char *input = NULL; */
/* 		ssize_t getline_val; */
/* 		size_t input_size = 0; */

/* 		print_str("($)"); */
/* 		getline_val = getline(&input, &input_size, stdin); */
/* 		if (getline_val == -1) */
/* 		{ */
/* 		} */
/* 		if (strlen(input) > 0 && input[strlen(input) - 1] == '\n') { */
/* 			input[strlen(input) - 1] = '\0'; */
/* 		} */
/* 		print_str("got here 0"); */
/* 		call_command(input); */
/* 		free(input); */
/* 		putchar('\n'); */
/* 	} while (1); */
/* 	return (0); */
/* } */
