#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack or queue
 * @n:integer number
 * @prev: points to the previous element of the stack or queue
 * @next: points to the previous element of the stack or queue
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
* struct match_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*/
typedef struct match_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} match_t;


/**
* struct data_s - variables -args, file, line content
* @arg: value
* @file: pointer to monty file
* @content: line content
* @qflag: flag change stack and queue
*/
typedef struct data_s
{
	char *arg;
	FILE *file;
	char *content;
	int qflag;
}  data_t;
extern data_t data;


int get_funct(char *content, stack_t **head, unsigned int counter, FILE *file);
void f_push(stack_t **head, unsigned int number);
void f_pall(stack_t **head, unsigned int counter);
void addnode(stack_t **head, int number);
void addqueue(stack_t **head, int number);
void free_stack(stack_t *head);

#endif
