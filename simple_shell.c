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
	int flag;

	if (isatty(0))
		printf("#csifun$ ");

	while ((read = my_getline(&command, &len, stdin)) != -1)
	{
		if (read != -1)
		{
			if (command[read - 1] == '\n')
				command[read - 1] = '\0';
		}

		if ((strcmp(command, "exit")) == 0)
			break;

		if ((strcmp(command, "env")) == 0)
			flag = print_env();

		if (flag != 100)
			child_process(command);

		flag = 0;
		printf("#cisfun$ ");
	}
	free(command);
	return (0);
}
