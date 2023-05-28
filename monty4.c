#include "monty.h"
/*global variable*/
int num;
/**
 * push_ - function that inserts new node in the beginning of the
 * doubly linked list
 * @put: pointer
 * @line: line
 */
void push_(stack_t **put, __attribute__((unused)) unsigned int line)
{
        stack_t *new_node = malloc(sizeof(stack_t));

        if (new_node == NULL)
        {
                fprintf(stderr, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }
        new_node->n = num;
        new_node->prev = NULL;

        if (*put == NULL)
        {
                new_node->next = NULL;
                *put = new_node;
        }
        else
        {
                new_node->next = *put;
                (*put)->prev = new_node;
                *put = new_node;
        }
}
/**
 * pall_ - function that prints all elements in a doubly linked list
 * @put: pointer
 * @line: line
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
/**
 * pint_ - function that prints the value of the top element
 * @top: pointer
 * @line: line
 */
void pint_(stack_t **put, unsigned int line)
{
        if (*put != NULL)
                printf("%d\n", (*put)->n);
        else
        {
                fprintf(stderr, "L%u: can't pint, stack empty\n", line);
                exit(EXIT_FAILURE);
        }
}
/**
 * pop_ - function that deletes the top element
 * @put: pointer
 * @line: line
 */
void pop_(stack_t **put, unsigned int line)
{
        stack_t *tmp = *put;

        if (*put == NULL)
        {
                fprintf(stderr, "L%u: can't pop an empty stack\n", line);
                exit(EXIT_FAILURE);
        }
        tmp = tmp->next;
        free(*put);
        *put = tmp;
}
/**
 * free_ - function that frees elements of stack
 * @put: pointer
 */
void free_(stack_t *put)
{
        stack_t *tmp;

        if (put == NULL)
                return;
        while (put != NULL)
        {
                tmp = put;
                put = put->next;
                free(tmp);
        }
        free(put);
}

