#ifndef SHELL_HEADER
#define SHELL_HEADER
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int take(char *in);
void print_str(char *str);
void perror_msg(char *msg);
void dispatcher(char *str);
char *str_chr(const char *s, int c);
char *str_tok(char *str, const char *delimiters);
int str_cmp(char *dest, char *src);
int str_len(const char *s);
char *str_dup(const char *str);
char *str_cat(char *dest,const char *src);
char *find_command(const char *command);
void free_tokens(char **tokens);
char **tokenize_command(const char *command);
char **parse_command(const char *command);
char *str_cpy(char *dest, char *src);
void exec_command(const char *command);
#endif
