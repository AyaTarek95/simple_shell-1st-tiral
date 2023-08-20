#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void execmd(char **argv);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *get_path(char *command);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);


#endif
