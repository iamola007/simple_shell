#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
* print_env - prints current environment
* Return: No return value
*/

int print_env(void)
{
	unsigned int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (100);
}
