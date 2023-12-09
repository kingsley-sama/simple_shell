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
char *_strchr(char *s, char c);
char *d_strtok(char *str, const char *dl);
int _strlen(char *s);
#endif
