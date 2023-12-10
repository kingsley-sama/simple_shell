#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

char** tokenize_command(const char *command) {
    const char *delimiter_space = " \t\n";
    const char *delimiter_semicolon = ";";

    char **tokens = NULL;
    int token_count = 0;

    // Tokenize the command based on semicolons
    char *token = strtok(strdup(command), delimiter_semicolon);

    while (token != NULL) {
        // Tokenize each part of the command based on spaces, respecting quotes
        char *subtoken;
        while ((subtoken = strtok(NULL, delimiter_space)) != NULL) {
            // Check if the subtoken contains quotes
            if (subtoken[0] == '\"') {
                // Concatenate tokens until a closing quote is found
                while (subtoken[strlen(subtoken) - 1] != '\"') {
                    char *next_subtoken = strtok(NULL, delimiter_space);
                    if (next_subtoken == NULL) {
                        fprintf(stderr, "Error: Unmatched quotes in command\n");
                        exit(EXIT_FAILURE);
                    }

                    // Concatenate the next subtoken to the current one
                    subtoken = realloc(subtoken, strlen(subtoken) + strlen(next_subtoken) + 2);
                    strcat(subtoken, " ");
                    strcat(subtoken, next_subtoken);
                }
            }

            tokens = realloc(tokens, sizeof(char *) * (token_count + 1));

            if (tokens == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }

            tokens[token_count] = strdup(subtoken);
            token_count++;
        }

        token = strtok(NULL, delimiter_semicolon);
    }

    tokens = realloc(tokens, sizeof(char *) * (token_count + 1));
    tokens[token_count] = NULL;

    return tokens;
}

void free_tokens(char **tokens) {
    if (tokens == NULL) {
        return;
    }

    for (int i = 0; tokens[i] != NULL; ++i) {
        free(tokens[i]);
    }

    free(tokens);
}

char* find_command(const char *command) {
    char *path = getenv("PATH");
    char *token = strtok(strdup(path), ":");

    while (token != NULL) {
        char *executable_path = malloc(strlen(token) + strlen(command) + 2);
        sprintf(executable_path, "%s/%s", token, command);

        if (access(executable_path, X_OK) == 0) {
            free(token);
            return executable_path;
        }

        free(executable_path);
        token = strtok(NULL, ":");
    }

    free(token);
    return NULL;
}

void execute_command(const char *command) {
    char *full_command = find_command(command);

    if (full_command == NULL) {
        fprintf(stderr, "Command '%s' not found\n", command);
        return;
    }

    // Fork a new process
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        // Tokenize the command into subcommands and arguments
        char **args = tokenize_command(full_command);

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

    free(full_command);
}

int main() {
    char input[MAX_COMMAND_LENGTH];

    // Read commands from the user
    printf("Enter commands (separated by ;):\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove newline if present

    // Tokenize the command
    char **commands = tokenize_command(input);

    // Execute the commands one after the other
    for (int i = 0; commands[i] != NULL; ++i) {
        execute_command(commands[i]);
    }

    // Free the allocated memory
    free_tokens(commands);

    return 0;
}
