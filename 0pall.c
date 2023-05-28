#include "monty.h"
/**
 * pall_ - prints the stack
 * @put: pushes the stack
 * @line: no used
 * Return: no return
*/
void pall_(stack_t **put, unsigned int line)
{
	stack_t *h;
	(void)line;

	 h = *put;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

