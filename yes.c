#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_TOKENS 128
#define MAX_COMMAND_LENGTH 100
char **parse_sub_command(const char *command)
{
	char **tokens = malloc(sizeof(char *) * MAX_COMMAND_LENGTH);
	int token_count = 0;
	const char *delimiter_space = " \t\n";
	char *subtoken;

	char *command_copy = strdup(command);
	if (command_copy == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	subtoken = strtok(command_copy, delimiter_space);

	while (subtoken != NULL) {
		if (subtoken[0] == '\"') {
			char *quoted_token = strdup(subtoken);

			while (quoted_token[strlen(quoted_token) - 1] != '\"') {
				char *next_subtoken = strtok(NULL, delimiter_space);
				if (next_subtoken == NULL) {
					fprintf(stderr, "Error: Unmatched quotes in command\n");
					exit(EXIT_FAILURE);
				}
				quoted_token = realloc(quoted_token, strlen(quoted_token) + strlen(next_subtoken) + 2);
				strcat(quoted_token, " ");
				strcat(quoted_token, next_subtoken);
			}

			tokens = realloc(tokens, sizeof(char *) * (token_count + 1));

			if (tokens == NULL) {
				fprintf(stderr, "Memory allocation failed\n");
				exit(EXIT_FAILURE);
			}

			tokens[token_count] = quoted_token;
			token_count++;
		} else if (subtoken[0] == '\\' && subtoken[1] != '\0') {
			char *next_subtoken = strtok(NULL, delimiter_space);
			if (next_subtoken != NULL) {
				subtoken = realloc(subtoken, strlen(subtoken) + strlen(next_subtoken) + 2);
				strcat(subtoken, next_subtoken);
			}
		} else {
			tokens = realloc(tokens, sizeof(char *) * (token_count + 1));

			if (tokens == NULL) {
				fprintf(stderr, "Memory allocation failed\n");
				exit(EXIT_FAILURE);
			}

			tokens[token_count] = strdup(subtoken);
			token_count++;
		}

		subtoken = strtok(NULL, delimiter_space);
	}
	free(command_copy);
	tokens = realloc(tokens, sizeof(char *) * (token_count + 1));
	if (tokens == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	tokens[token_count] = NULL;
	return tokens;
}

char **parse_command(const char *str) {
  char **tokens = malloc(sizeof(char *) * MAX_TOKENS);
  if (!tokens) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }

  int i = 1;
  char *token = strtok(strdup(str), ";");
  tokens[0] = token;
  while (str[i]  != '\0')
  {
	  token = strtok(NULL, ";");
	  tokens[i] = token;
	  i++;
  }
  return tokens;
}


/**
 * free_token- Frees the allocated memory.
 * @tokens: A pointer to the string(tokens)
 *
 * Return: void.
 */
void free_tokens(char **tokens) {
	if (tokens == NULL) {
		return;
	}
	free(tokens);
}
void strip_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';  // Replace newline with null terminator
    }
}

void call_command(const char *str) {
    // Duplicate the input string to avoid modifying the original
    char *input_copy = strdup(str);
    if (input_copy == NULL) {
        perror("strdup");
        exit(EXIT_FAILURE);
    }

    strip_newline(input_copy);

    char **tokens = parse_command(input_copy);
    char **sub_commands = NULL;

    for (int i = 0; tokens[i] != NULL; i++) {
        sub_commands = parse_sub_command(tokens[i]);
        exec_command(sub_commands);
        printf("Token %d %d: %s\n", i + 1, (int)strlen(sub_commands[0]), sub_commands[0]);
    }

    free_tokens(tokens);
    free(input_copy);
}

