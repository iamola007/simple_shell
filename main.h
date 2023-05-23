#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
extern char **environ;
int print_env(void);
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
void child_process(char *command);
#endif
