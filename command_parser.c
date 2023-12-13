/* #include "shell.h" */
/* #include <stdio.h> */
/* #include <stdlib.h> */
/* #include <string.h> */
/* #include <unistd.h> */
/* #include <sys/wait.h> */
/* #define MAX_COMMAND_LENGTH 100 */



/* char **parse_sb_command(const char *command) */
/* { */
/* 	char **tokens = malloc(sizeof(char *) * MAX_COMMAND_LENGTH); */
/* 	int token_count = 0; */
/* 	const char *delimiter_space = " \t\n"; */
/* 	char *subtoken; */

/* 	char *command_copy = strdup(command); */
/* 	if (command_copy == NULL) { */
/* 		fprintf(stderr, "Memory allocation failed\n"); */
/* 		exit(EXIT_FAILURE); */
/* 	} */

/* 	subtoken = strtok(command_copy, delimiter_space); */

/* 	while (subtoken != NULL) { */
/* 		if (subtoken[0] == '\"') { */
/* 			char *quoted_token = strdup(subtoken); */

/* 			while (quoted_token[strlen(quoted_token) - 1] != '\"') { */
/* 				char *next_subtoken = strtok(NULL, delimiter_space); */
/* 				if (next_subtoken == NULL) { */
/* 					fprintf(stderr, "Error: Unmatched quotes in command\n"); */
/* 					exit(EXIT_FAILURE); */
/* 				} */
/* 				quoted_token = realloc(quoted_token, strlen(quoted_token) + strlen(next_subtoken) + 2); */
/* 				strcat(quoted_token, " "); */
/* 				strcat(quoted_token, next_subtoken); */
/* 			} */

/* 			tokens = realloc(tokens, sizeof(char *) * (token_count + 1)); */

/* 			if (tokens == NULL) { */
/* 				fprintf(stderr, "Memory allocation failed\n"); */
/* 				exit(EXIT_FAILURE); */
/* 			} */

/* 			tokens[token_count] = quoted_token; */
/* 			token_count++; */
/* 		} else if (subtoken[0] == '\\' && subtoken[1] != '\0') { */
/* 			// Handle escape characters */
/* 			char *next_subtoken = strtok(NULL, delimiter_space); */
/* 			if (next_subtoken != NULL) { */
/* 				// Concatenate the next subtoken to the current one */
/* 				subtoken = realloc(subtoken, strlen(subtoken) + strlen(next_subtoken) + 2); */
/* 				strcat(subtoken, next_subtoken); */
/* 			} */
/* 		} else { */
/* 			// Handle regular tokens */
/* 			tokens = realloc(tokens, sizeof(char *) * (token_count + 1)); */

/* 			if (tokens == NULL) { */
/* 				fprintf(stderr, "Memory allocation failed\n"); */
/* 				exit(EXIT_FAILURE); */
/* 			} */

/* 			tokens[token_count] = strdup(subtoken); */
/* 			token_count++; */
/* 		} */

/* 		subtoken = strtok(NULL, delimiter_space); */
/* 	} */

/* 	// Don't forget to free the copied command */
/* 	free(command_copy); */

/* 	// Add a NULL pointer at the end to indicate the end of the array */
/* 	tokens = realloc(tokens, sizeof(char *) * (token_count + 1)); */
/* 	if (tokens == NULL) { */
/* 		fprintf(stderr, "Memory allocation failed\n"); */
/* 		exit(EXIT_FAILURE); */
/* 	} */
/* 	tokens[token_count] = NULL; */

/* 	return tokens; */
/* } */
