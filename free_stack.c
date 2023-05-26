#include "monty.h"
/**
* free_stack - frees a doubly linked list
* @head: head of the stack
*/
void free_stack(stack_t *head)
{
stack_t *aux;
aux = head;
while (head)
{
aux = head->next;
free(head);
head = aux;
}
}

#include "monty.h"
/**
 * f_stack - function that doesn't do anything
 * @head: double pointer to head node
 * @counter: line_number
 * Return: 0
*/
void f_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}
