#ifndef _SHELL_H_
#define _SHELL_H_
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/* Pass_betty_checks */
int repeated_char(char *input, int a);
int error_sep_op(char *input, int a, char end);
int first_char(char *input, int *a);
int check_betty_error(data_shell *datash, char *input)
void print_betty_error(data_shell *datash, char *input, int a, int bool);

/* main */
int main(int ac, char **av, char **env);

/* shell functions */
void prompt(void);
void handle(int signals);
void _EOF(char *buffer);
void shell_exit(char **command);

/* create child */
void create_child(char **command, char *name, char **env, int count);
int change_dir(const char *path);

/* execute */
void execute(char **command, char *name, char **env, int count);
void print_env(char **env);
char **_getPATH(char **env);
void msg_error(char *name, int count, char **command);

/* token */
char **tokening(char *buffer, const char *s);

/* free memory */
void free_dp(char **command);
void free_exit(char **command);

/* auxillary functions */
int _strcmp(char *s1, char *s2);
unsigned int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _atoi(char *s);

/* env2.c */
char *copy_info(char *info, char *value);
void set_env(char *info, char *value, data_shell *datash);
int _setenv(data_shell *datash);
int _unsetenv(data_shell *datash);

/* cd_home.c */
int cd_shell(data_shell *value);

/* alias.c */
int _myhistory(info_t *);
int _myalias(info_t *);

/* aux_var.c */
char *strcat_cd(data_shell *, char *, char *, char *);
char *error_get_cd(data_shell *datash);
char *error_not_found(data_shell *datash);
char *error_exit_shell(data_shell *datash);

/* aux_var.c */
char *error_get_alias(char **args);
char *error_env(data_shell *datash);
char *error_syntax(char **args);
char *error_permission(char **args);
char *error_path_126(data_shell *datash);

#endif /* _SHELL_H_ */

