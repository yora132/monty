#include "monty.h"
#define _GNU_SOURCE


data_t data = {NULL, NULL, NULL, 0};

/**
* main - function for monty code interpreter
* @argc: argument counter
* @argv: argument value
*
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_l = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	data.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read_l > 0)
	{
		content = NULL;
		read_l = getline(&content, &size, file);
		data.content = content;
		counter++;
		if (read_l > 0)
		{
			get_funct(content, &stack, counter, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
