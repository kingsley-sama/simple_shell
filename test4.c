#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **tokenizeString(const char *input, const char *delimiter_space, const char *delimiter_semicolon, int *token_count) {
    char **tokens = NULL;
    char *token;
    char *subtoken;

    *token_count = 0;

    // Tokenize using space delimiter
    token = strtok((char *)input, delimiter_space);

    while (token != NULL) {
        subtoken = strdup(token);

        // Check if the subtoken contains quotes
        if (subtoken[0] == '\"') {
            char *buffer = subtoken;

            // Concatenate tokens until a closing quote is found
            while (buffer[strlen(buffer) - 1] != '\"') {
                char *next_subtoken = strtok(NULL, delimiter_space);
                if (next_subtoken == NULL) {
                    fprintf(stderr, "Error: Unmatched quotes in command\n");
                    exit(EXIT_FAILURE);
                }

                // Concatenate the next subtoken to the buffer
                buffer = realloc(buffer, strlen(buffer) + strlen(next_subtoken) + 2);
                strcat(buffer, " ");
                strcat(buffer, next_subtoken);
            }

            // Assign the concatenated string to subtoken
            subtoken = buffer;
        } else if (subtoken[0] == '\\' && subtoken[1] != '\0') {
            // Handle escape characters
            char *buffer = subtoken;

            char *next_subtoken = strtok(NULL, delimiter_space);
            if (next_subtoken != NULL) {
                // Concatenate the next subtoken to the buffer
                buffer = realloc(buffer, strlen(buffer) + strlen(next_subtoken) + 2);
                strcat(buffer, " ");
                strcat(buffer, next_subtoken);
            }

            // Assign the concatenated string to subtoken
            subtoken = buffer;
        }

        tokens = realloc(tokens, sizeof(char *) * (*token_count + 1));

        if (tokens == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }

        tokens[*token_count] = subtoken;
        (*token_count)++;

        token = strtok(NULL, delimiter_space);
    }

    // Tokenize using semicolon delimiter
    token = strtok(NULL, delimiter_semicolon);

    return tokens;
}

int main() {
    const char *inputString = "token1 \"quoted token\" token2 \\ escape\\ token token3;token4";
    const char *delimiter_space = " \t\n";
    const char *delimiter_semicolon = ";";

    int token_count;
    char **tokens = tokenizeString(inputString, delimiter_space, delimiter_semicolon, &token_count);

    // Print the tokens
    for (int i = 0; i < token_count; ++i) {
        printf("Token %d: %s\n", i + 1, tokens[i]);
        free(tokens[i]); // Free each token
    }

    free(tokens); // Free the array of tokens

    return 0;
}
