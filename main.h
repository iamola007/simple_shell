#ifndef MAIN_H
#define MAIN_H
extern char **environ;
int print_env(void);
void child_process(char *command);
#endif
