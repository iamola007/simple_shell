#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
* main - simple shell to run  commands with full path
* Return: Always 0
*/
int main(void)
{
	char  *command = NULL;

	ssize_t read;

	size_t len = 0;

	if (isatty(0))
		printf("#csifun ");

	while ((read = getline(&command, &len, stdin)) != -1)
	{

		if (read != -1)
		{
			if (command[read - 1] == '\n')
				command[read - 1] = '\0';
		}

		if ((strcmp(command, "exit")) == 0)
			break;

		child_process(command);
		printf("#cisfun$ ");
	}
	free(command);
	return (0);
}
