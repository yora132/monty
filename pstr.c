#include "monty.h"
/**
 * f_pstr - prints the string starting at the top
 * of the stack (ASCII) value of the node 
 * @head: double pointer to head node
 * @counter: line_number
 * Return: void
*/
void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
