#ifndef SHELL_HEADER
#define SHELL_HEADER
#define PRINT(c) (write(STDERR_FILENO, c, str_len(c)))
#define BUFSIZE 10240
#define DELIMITER " \t\r\n\a"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

void free_env(char **env);
void *fill_an_array(void *a, int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_all(char **input, char *line);
char *strn_cpy(char *dest, char *src, int n);
int str_len(char *s);
int put_char(char c);
int ato_i(char *s);
void put_s(char *str);
int str_cmp(char *s1, char *s2);
int is_alpha(int c);
void rev(char *arr, int len);
int intlen(int num);
char *ito_a(unsigned int n);
char *str_cat(char *dest, char *src);
char *str_cpy(char *dest, char *src);
char *str_chr(char *s, char c);
int strn_cmp(const char *s1, const char *s2, size_t n);
char *str_dup(char *str);
void print_str(char *str);
char *get_line();
char *space(char *str);
char *enter(char *string);
void hashtag_handler(char *buff);
void prompt(void);
unsigned int check_delim(char c, const char *str);
char *str_tok(char *str, const char *delim);
int history(char *input);
char **separator(char *input);



void read_file(char *file, char **argv);
void treat_file(char *line, int count, FILE *fp, char **argv);
void exit_bull(char **cmd, char *line, FILE *fd);
char **parse_cmd(char *input);
int handle_builtin(char **cmd, int er);
int check_cmd(char **cmd, char *input, int c, char **argv);
void signal_to_handle(int sig);
void print_error(char *input, int counter, char **argv);
void _prerror(char **argv, int c, char **cmd);
void error_file(char **argv, int c);
extern char **environ;
void create_envi(char **envi);
void free_env(char **env);
void print_number(unsigned int n);
void print_number_int(int n);
int print_echo(char **cmd);
int path_cmd(char **cmd);
char *build(char *token, char *value);
char *get_env(char *name);
void help_env(void);
void help_setenv(void);
void help_unsetenv(void);
void help_history(void);
void help_all(void);
void help_alias(void);
void help_cd(void);
void help_exit(void);
void help_help(void);
int display_help(char **cmd, __attribute__((unused))int st);
int check_builtin(char **cmd);
int handle_builtin(char **cmd, int st);
void exit_bul(char **cmd, char *input, char **argv, int c, int stat);
int change_dir(char **cmd, __attribute__((unused))int st);
int dis_env(__attribute__((unused)) char **cmd,
	    __attribute__((unused)) int st);
int echo_bul(char **cmd, int st);
int history_dis(__attribute__((unused))char **c,
		__attribute__((unused)) int st);


/**
 * struct shell_funciton - Defines a struct that conatins built-in commands
 * with their respective implementation functions
 * @command: - Built-in command
 * @function: - Pointer to custom functions that have
 * similar functionalities as the built-in commands
 */
typedef struct shell_functions
{
	char *command;
	int (*function)(char **line, int st);
} shell_builtin;

#endif
