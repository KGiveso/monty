#include "monty.h"                                /**
*swap_ - function that swap two elements of stack
* @put: pointer
* @line: line
*/
void swap_(stack_t **put, unsigned int line)
{
int tmp_num;
if (*put == NULL || (*put)->next == NULL)
{
fprintf(stderr, "L%u: can't swap, stack too short\n", line);
exit(EXIT_FAILURE);
}
tmp_num = (*put)->n;
(*put)->n = (*put)->next->n;
(*put)->next->n = tmp_num;
}
/**
* nop_ - funcction that does nothing
* @put: pointer
* @line: line
*/
void nop_(stack_t **put, unsigned int line)
{
(void) put;
(void) line;
}
