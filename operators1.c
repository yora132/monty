#include "monty.h"

/**
* f_pall - function that prints everything
* @head: double head pointer to the stack
* @counter: unused line
* Return: nothing
*/
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *m;
	(void)counter;

	m = *head;
	if (m == NULL)
		return;
	while (m)
	{
		printf("%d\n", m->n);
		m = m->next;
	}
}
