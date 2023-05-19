#ifndef _SHELL_H_
#define _SHELL_H_
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

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

#endif /* _SHELL_H_ */
