#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

/**
 * tokenize_command- A command that tokenises.
 * @command: The input command.
 *
 * Return: The tokenised command.
 */
char** tokenize_command(const char *command) {
    const char *delimiter_space = " \t\n";
    const char *delimiter_semicolon = ";";

    char **tokens = NULL;
    int token_count = 0;

    // Tokenize the command based on semicolons
    char *token = strtok(strdup(command), delimiter_semicolon);

    while (token != NULL) {
        // Tokenize each part of the command based on spaces
        char *subtoken = strtok(token, delimiter_space);

        while (subtoken != NULL) {
            tokens = realloc(tokens, sizeof(char *) * (token_count + 1));

            if (tokens == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }

            tokens[token_count] = strdup(subtoken);
            token_count++;

            subtoken = strtok(NULL, delimiter_space);
        }

        token = strtok(NULL, delimiter_semicolon);
    }

    tokens = realloc(tokens, sizeof(char *) * (token_count + 1));
    tokens[token_count] = NULL;

    return tokens;
}

/**
 * free_tokens- Frees allocated memory.
 * @token:Pointer that points to the string.
 *
 * Return: Void
 */
void free_tokens(char **tokens) {
    if (tokens == NULL) {
        return;
    }

    for (int i = 0; tokens[i] != NULL; ++i) {
        free(tokens[i]);
    }

    free(tokens);
}
/**
 * execute_command- Executes command.
 * @command: The input command.
 *
 * Return: void.
 */

void execute_command(const char *command) {
    // Fork a new process
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        // Tokenize the command into subcommands and arguments
        char **args = tokenize_command(command);

        // Execute the command
        if (args[0] != NULL && execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }

        // Free the allocated memory for command arguments
        free_tokens(args);
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            printf("Command exited with status %d\n", WEXITSTATUS(status));
        }
    }
}

/**
 * main- Entry point.
 * 
 * Return:0
 */
int call(char *input) {
    char *commands[] = {
        "ls -l -a",
        "ls -la",
        "echo Hello World\"\n\'",
        "gcc -v",
        NULL  // NULL-terminate the array
    };

    // Execute the commands one after the other
    for (int i = 0; commands[i] != NULL; ++i) {
        execute_command(commands[i]);
    }

    return 0;
}
