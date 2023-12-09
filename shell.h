#ifndef SHELL_HEADER
#define SHELL_HEADER
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void print_str(char *str);
void perror_msg(char *msg);
int  print_current_directory(void);
void dispatcher(char *str);
char *str_chr(const char *s, int c);
char *str_tok(char *str, const char *delimiters);
int str_len(char *s);
int str_cmp(char *dest, char *src);
#endif
