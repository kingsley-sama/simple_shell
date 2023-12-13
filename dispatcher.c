#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_TOKENS 1024
#define MAX_COMMAND_LENGTH 1024
/**
 * tok_quotes - Tokenizes a quoted subcommand.
 * @q_toks: The quoted subcommand to be tokenized.
 * @de_sp: The delimiter used for tokenization.
 * This function takes a quoted subcommand as input and returns a dynamically
 * allocated string representing the tokenized subcommand, handling quotes and
 * concatenation of multiple parts.
 *
 * Return: A dynamically a.
 */
char *tok_quotes(char *q_toks, const char *de_sp)
{
	char *n_sbtn;

	while (q_toks[strlen(q_toks) - 1] != '\"')
	{
		n_sbtn = strtok(NULL, de_sp);
		q_toks = realloc(q_toks, strlen(q_toks) + strlen(n_sbtn) + 2);
		strcat(q_toks, " ");
		strcat(q_toks, n_sbtn);
	}
	q_toks[strlen(q_toks) - 1] = '\0';
	return (q_toks);
}

/**
 * parse_sub_command - Parses command into subcommands.
 * @command: The input command to be parsed.
 *
 * This function takes a command as input and tokenizes it into subcommands,
 * handling regular, quoted, and escape-character scenarios. The result is an
 * array of strings representing the individual subcommands.
 *
 * Return: An array of strings representing subcommands (tokens).
 */
char **parse_sub_command(const char *command)
{
	char **tokens = malloc(sizeof(char *) * MAX_COMMAND_LENGTH);
	int token_count = 0;
	const char *de_sp = " \t\n";
	char *subtoken, *command_copy;
	char *q_toks;
	char *n_sbtn;

	command_copy = strdup(command);
	subtoken = strtok(command_copy, de_sp);
	while (subtoken != NULL)
	{
		if (subtoken[0] == '\"')
		{
			q_toks = tok_quotes(strdup(subtoken + 1), de_sp);
			tokens = realloc(tokens, sizeof(char *) * (token_count + 1));
			q_toks[strlen(q_toks) - 1] = '\0';
			tokens[token_count] = q_toks;
			token_count++;
		} else if (subtoken[0] == '\\' && subtoken[1] != '\0')
		{
			n_sbtn = strtok(NULL, de_sp);
			if (n_sbtn != NULL)
			{
				subtoken = realloc(subtoken, strlen(subtoken) + strlen(n_sbtn) + 2);
				strcat(subtoken, n_sbtn);
			}
		} else
		{
			tokens = realloc(tokens, sizeof(char *) * (token_count + 1));
			tokens[token_count] = strdup(subtoken);
			token_count++;
		}
		subtoken = strtok(NULL, de_sp);
	}
	free(command_copy);
	tokens = realloc(tokens, sizeof(char *) * (token_count + 1));
	tokens[token_count] = NULL;
	return (tokens);
}
/**
 *parse_command - parses command int an array of subcommands
 *@str: array of command
 *Return: subcommand
 */
char **parse_command(const char *str)
{
	char **tokens = malloc(sizeof(char *) * MAX_TOKENS);
	int i = 1;
	char *token = strtok(strdup(str), ";");

	if (!tokens)
		exit(1);
	tokens[0] = token;
	while (str[i]  != '\0')
	{
		token = strtok(NULL, ";");
		tokens[i] = token;
		i++;
	}
	return (tokens);
}

/**
 * free_tokens - Frees the allocated memory.
 * @tokens: A pointer to the string(tokens)
 * Return: void.
 */
void free_tokens(char **tokens)
{
	if (tokens == NULL)
		return;
	free(tokens);
}

/**
 * call_command - Frees the allocated memory.
 * @str: A pointer to the string(tokens)
 * Return: int.
 */
void call_command(const char *str)
{
	int i;
	char *input_copy = strdup(str);
	char **tokens = parse_command(input_copy);
	char **sub_commands = NULL;

	if (input_copy == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}
	for (i = 0; tokens[i] != NULL; i++)
	{
		sub_commands = parse_sub_command(tokens[i]);
		exec_command(sub_commands);


	}
	free_tokens(tokens);
	free(input_copy);
}
