#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **tokenize_string(const char *input, const char *delimiter);

char **tokenize_command(const char *command);

int main() {
    const char *command = "command1 arg1 arg2 ; command2 \"arg 1\" arg3 ; command3 arg4";

    char **semicolon_tokens = tokenize_command(command);

    for (int i = 0; semicolon_tokens[i] != NULL; ++i) {
        char **space_tokens = tokenize_string(semicolon_tokens[i], " \t\n");

        for (int j = 0; space_tokens[j] != NULL; ++j) {
            printf("Token %d-%d: %s\n", i + 1, j + 1, space_tokens[j]);
        }

        for (int j = 0; space_tokens[j] != NULL; ++j) {
            free(space_tokens[j]);
        }
        free(space_tokens);
    }

    for (int i = 0; semicolon_tokens[i] != NULL; ++i) {
        free(semicolon_tokens[i]);
    }
    free(semicolon_tokens);

    return 0;
}

char **tokenize_string(const char *input, const char *delimiter) {
    char **tokens = NULL;
    int token_count = 0;

    char *token = strtok(strdup(input), delimiter);
    while (token != NULL) {
        tokens = realloc(tokens, sizeof(char *) * (token_count + 1));

        if (tokens == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }

        tokens[token_count] = strdup(token);
        token_count++;

        token = strtok(NULL, delimiter);
    }

    tokens = realloc(tokens, sizeof(char *) * (token_count + 1));
    tokens[token_count] = NULL;

    return tokens;
}

char **tokenize_command(const char *command) {
    return tokenize_string(command, ";");
}
