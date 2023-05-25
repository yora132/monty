#include "monty.h"

/**
* get_funct - function that select the right function
* @stack: head stack linked list
* @counter: line count
* @file: pointer to monty file
* @content: line content
*
* Return: nothing
*/
int get_funct(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	match_t opt[] = {
			{"push", f_push}, {"pall", f_pall}, {NULL, NULL}
			};

	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	data.arg = strtok(NULL, " \n\t");
	while (opt[i].opcode && op)
	{
		if (strcmp(op, opt[i].opcode) == 0)
		{	opt[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opt[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
