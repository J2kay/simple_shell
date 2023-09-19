#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
int built_in_do(char **arg, char *buffer);
int pro_start(char **arg, char *filepath);
int first_pro_start(char **arg);
char **read_com(char *str);
char *prompt(void);
char *com_path(char *com);
int my_exit(char **arg, char *buffer);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
extern char **environ;
int my_env(char **arg, char *buffer);
char *my_getenv(const char *name);
void my_free(char **mem);
int _putchar(char c);
void _puts(char *str);
void error_print(char *str, int counter, char *arg);
#endif
