/* #include <stdio.h> */
/* #include <stdlib.h> */
/* #include <string.h> */
/* #define MAX_COMMAND_LENGTH 100 */
/* /\** */
/*  * tokenize_command- The command that tokenises a string. */
/*  * @command: The input command. */
/*  * @delimiter:The delimiter in the string. */
/*  * Return: Tokenised command. */
/*  *\/ */
/* char** tokenize_command(const char *command, const char *delimiter) */
/* { */
/*     char **tokens = NULL; */
/*     int token_count = 0; */

/*     char *token = strtok(strdup(command), delimiter); */
    
/*     while (token != NULL) */
/*     { */
/*         tokens = realloc(tokens, sizeof(char *) * (token_count + 1)); */
/*         if (tokens == NULL) { */
/*             fprintf(stderr, "Memory allocation failed\n"); */
/*             exit(EXIT_FAILURE); */
/*         } */
/*         tokens[token_count] = strdup(token); */
/*         token_count++; */
/*         token = strtok(NULL, delimiter); */
/*     } */
/*     tokens = realloc(tokens, sizeof(char *) * (token_count + 1)); */
/*     tokens[token_count] = NULL; */
/*     return tokens; */
/* } */
/* /\** */
/*  * free_tokens- Frees allocated memory. */
/*  * @tokens:Pointer that points to the string. */
/*  * Return: void. */
/*  *\/ */
/* void free_tokens(char **tokens) */
/* { */
/*     for (int i = 0; tokens[i] != NULL; ++i) { */
/*         free(tokens[i]); */
/*     } */
/*     free(tokens); */
/* } */

