#include "monty.h"
/**
 * push_ - function that pushes an element to the stack
 * @put: pointer to the stack
 * @line: line number
 * @arg: argument to push
 */
void push_(stack_t **put, unsigned int line, char *arg)
{
	int n;

	if (!arg || !isdigit(*arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}

	n = atoi(arg);

	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "L%u: out of memory\n", line);

		exit(EXIT_FAILURE);

	}
	new_node->n = n;

	new_node->next = *put;

	*put = new_node;
}

/**
 * pall_ - function that prints all elements in a doubly linked list
 * @put: pointer to the stack
 * @line: line number
 */
void pall_(stack_t **put, __attribute__((unused)) unsigned int line)
{
	stack_t *tmp = *put;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

