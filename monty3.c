#include "monty.h"
/**
* add_ - function that adds  two elements of stack
* @put: pointer
* @line: line
*/
void add_(stack_t **put, unsigned int line)
{
stack_t *tmp;

if (*put == NULL || (*put)->next == NULL)
{
fprintf(stderr, "L%u: can't add, stack too short\n", line);
exit(EXIT_FAILURE);
}
tmp = (*put)->next;
tmp->n += (*put)->n;
pop_(put, line);
}
/**
* sub_ - function that subtract the value of two elements of stack
* @put: pointer
* @line: line
*/
void sub_(stack_t **put, unsigned int line)
{
stack_t *tmp;

if (*put == NULL || (*put)->next == NULL)
{
fprintf(stderr, "L%u: can't sub, stack too short\n", line);
exit(EXIT_FAILURE);
}
tmp = (*put)->next;
tmp->n -= (*put)->n;
pop_(put, line);
}
/**
* div_ - function that divides the second  element by put element
* @put: pointer
* @line: line
*/
void div_(stack_t **put, unsigned int line)
{
stack_t *tmp;

if (*put == NULL || (*put)->next == NULL)
{
fprintf(stderr, "L%u: can't div, stack too short\n", line);
exit(EXIT_FAILURE);
}
if ((*put)->n == 0)
{
fprintf(stderr, "L%u: division by zero\n", line);
exit(EXIT_FAILURE);
}
tmp = (*put)->next;
tmp->n /= (*put)->n;
pop_(put, line);
}
/**
* mul_ - function that multiplies  two elements of stack
* @put: pointer
* @line: line
*/
void mul_(stack_t **put, unsigned int line)
{
stack_t *tmp;

if (*put == NULL || (*put)->next == NULL)
{
fprintf(stderr, "L%u: can't mul, stack too short\n", line);
exit(EXIT_FAILURE);
}
tmp = (*put)->next;
tmp->n *= (*put)->n;
pop_(put, line);
}
/**
* mod_ - function that computes the rest of the division of the second
* put element of the stack by the  element of the stack
* @put: pointer
* @line: line
*/
void mod_(stack_t **put, unsigned int line)
{

stack_t *tmp;

if (*put == NULL || (*put)->next == NULL)
{
fprintf(stderr, "L%u: can't mod, stack too short\n", line);
exit(EXIT_FAILURE);
}
if ((*put)->n == 0)
{
fprintf(stderr, "L%u: division by zero\n", line);
exit(EXIT_FAILURE);
}
tmp = (*put)->next;
tmp->n %= (*put)->n;
pop_(put, line);
}
