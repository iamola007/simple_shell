#include "main.h"
/**
* my_getline - implements custome getline function
* @lineptr: pointer to char variable (buffer)
* @n: size of buffer
* @stream: pointer to input stream
* Return: number of characters read (ssize_t)
*/
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t capacity;
	char *buffer = *lineptr;
	size_t count = 0;
	int c;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	capacity = *n;
	while ((c = getc(stream)) != EOF)
	{
		if ((count + 1) >= capacity)
		{
			if (capacity != 0)
				capacity *= 2;
			else
				capacity = 16;

			buffer = realloc(buffer, capacity);

			if (buffer == NULL)
				return (-1);

			*lineptr = buffer;
			*n = capacity;
		}

		buffer[count++] = (char)c;
		if (c == '\n')
			break;
	}

	if (count == 0)
		return (-1);

	buffer[count] = '\0';
	return (count);
}
