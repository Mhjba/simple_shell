#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

extern char **environ;

char *get_line(void);
char **splits(char *str);
int execute(char **array, char **argv, int buf);
void free_str(char **argv);

char *_strdup(char *str);
int _strlen(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);

char *_getenv(char *var);
char *_path(char *path);
void p_err(char *len, char *buf, int d);
char *_atoi(int buf);
void rev_str(char *str, int len);

#endif
