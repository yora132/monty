#include "monty.h"

/**
* f_push - function that adds node
* @head: double head pointer to the stack
* @counter: line count
* Return: nothing
*/

void f_push(stack_t **head, unsigned int counter)
{
	int i, j = 0, flag = 0;

	if (data.arg)
	{
		if (data.arg[0] == '-')
			j++;
		for (; data.arg[j] != '\0'; j++)
		{
			if (data.arg[j] > 57 || data.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(data.file);
			free(data.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(data.file);
		free(data.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	i = atoi(data.arg);
	if (data.qflag == 0)
		addnode(head, i);
	else
		addqueue(head, i);
}
