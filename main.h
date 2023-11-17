#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

char *my_getline(void);
char **my_strtok(char *line);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
void free2d(char **array);
int my_exec(char **cmd, char **argv);
int _atoi(char *s);
int _strlen(char *str);

#endif
