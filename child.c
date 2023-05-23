#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"

/**
* child_process - takes user input and runs in new process
* @input: pointer to character (user cammnad)
* Return: No return value
*/
void child_process(char *input)
{
	pid_t child_pid;

	char *command = strtok(input, " ");
	char *params = strtok(NULL, " ");

	char *argv[3];
	char **env = {NULL};

	argv[0] = command;
	argv[1] = params;
	argv[2] = NULL;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(input, argv, env) == -1)
		{
			perror("./shell");
			exit(1);
		}
	}
	else
	{
		wait(NULL);
	}
}
