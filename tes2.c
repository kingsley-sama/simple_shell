#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>

#define MAX_COMMAND_LENGTH 100

/**
 * tokenize_command- A command that tokenises.
 * @command: The input command.
 *
 * Return:The tokenised command.
 */

char** tokenize_command(const char *command) {
    const char *delimiter_semicolon = ";";

    char **tokens = NULL;
    int token_count = 0;

    // Tokenize the command based on semicolons
    char *token = strtok(strdup(command), delimiter_semicolon);

    while (token != NULL) {
        tokens = realloc(tokens, sizeof(char *) * (token_count + 1));

        if (tokens == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }

        tokens[token_count] = strdup(token);
        token_count++;

        token = strtok(NULL, delimiter_semicolon);
    }

    tokens = realloc(tokens, sizeof(char *) * (token_count + 1));
    tokens[token_count] = NULL;

    return tokens;
}

/**
 * free_tokens:Frees the memory allocated to string(tokens).
 * @tokens: The pointer to the tokenise string.
 *
 * Return:void.
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
 * find_executable- Command that find and execute an executable.
 * @command: The input command.
 *
 * Return:0(success)
 */
char* find_executable(const char *command) {
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

/**
 * execute_command- Exexutes commands.
 * @command: The input command.
 *
 * Return: void.
 */

void execute_command(const char *command) {
    char *executable_path = find_executable(command);
    
    if (executable_path == NULL) {
        fprintf(stderr, "Command '%s' not found\n", command);
        return;
    }
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        char **args = tokenize_command(command);
        if (execv(executable_path, args) == -1) {
            perror("execv");
            exit(EXIT_FAILURE);
        }
        free_tokens(args);
    } else {
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            printf("Command exited with status %d\n", WEXITSTATUS(status));
        }
    }
    free(executable_path);
}

/**
 * main- Entry point
 * Return:0(always)
 */
int main() {
    char *commands[] = {
        "ls -l -a",
        "ls -la",
        "echo Hello World",
        "gcc -v",
        NULL
    };
    for (int i = 0; commands[i] != NULL; ++i)
    {
        execute_command(commands[i]);
    }

    return 0;
}
