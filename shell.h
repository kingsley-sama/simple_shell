#ifndef SHELL_HEADER
#define SHELL_HEADER
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void print_str(char *str);
void perror_msg(char *msg);
int  print_current_directory(void);
void ls_file(const char *dir);
void dispatcher(char *str);
char *d_strtok(char *str, const char *dl);
#endif
