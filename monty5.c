#include "monty.h"
/**
* pchar_ - function that prints the char at the top of the stack
* followed by a new line
* @put: pointer
* @line: line
*/
void pchar_(stack_t **put, unsigned int line)
{
int c;

if (*put  == NULL)
{
fprintf(stderr, "L%u: can't pchar, stack empty\n", line);
exit(EXIT_FAILURE);
}

c = (*put)->n;
if (c < 0 || c > 127)
{
fprintf(stderr, "L%u: can't pchar, value out of range\n", line);
exit(EXIT_FAILURE);
}

putchar(c);
putchar('\n');
}
/**
* pstr_ - function that prints the string starting at the stack
* @put: pointer
* @line: line
*/
void pstr_(stack_t **put, __attribute__((unused)) unsigned int line)
{
int s;
stack_t *tmp;

if (*put == NULL)
{
putchar('\n');
return;
}
tmp = *put;
while (tmp != NULL)
{
s = tmp->n;
if (s <= 0 || s > 127)
break;
putchar(s);
tmp = tmp->next;
}
putchar('\n');
}
/**
* rotl_ - function that rotates the stack to the top
* @put: pointer
* @line: line
*/
void rotl_(stack_t **put, __attribute__((unused)) unsigned int line)
{
stack_t *tmp, *new_put, *h;

if (*put == NULL || (*put != NULL && (*put)->next == NULL))
return;
tmp = *put;
h = *put;

while (tmp->next)
tmp = tmp->next;
new_put = (*put)->next;
h->next = NULL;
h->prev = tmp;
tmp->next = h;
new_put->prev = NULL;
*put = new_put;
}
/**
* rotr_ - function that rotates the stack to the bottom
* @put: pointer
* @line: line
*/
void rotr_(stack_t **put, __attribute__((unused)) unsigned int line)
{
stack_t *tmp;

if (*put == NULL || (*put != NULL && (*put)->next == NULL))
return;
tmp = *put;
while (tmp->next)
tmp = tmp->next;
tmp->prev->next = NULL;
tmp->prev = NULL;
tmp->next = *put;
(*put)->prev = tmp;
*put = tmp;
}
