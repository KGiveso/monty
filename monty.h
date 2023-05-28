#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>

/*  extern int n */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* basic operations functions */
void push_(stack_t **put, unsigned int line);
void pall_(stack_t **put, unsigned int line);
void pint_(stack_t **put, unsigned int line);
void pop_(stack_t **put, unsigned int line);
void free_(stack_t *put);

/* math operations functions */
void swap_(stack_t **put, unsigned int line);
void add_(stack_t **put, unsigned int line);
void sub_(stack_t **put, unsigned int line);
void div_(stack_t **put, unsigned int line);
void mul_(stack_t **put, unsigned int line);
void mod_(stack_t **put, unsigned int line);
void rotl_(stack_t **put, unsigned int line);
void rotr_(stack_t **put, unsigned int line);
void nop_(stack_t **put, unsigned int line);

/* char and string functions */
void pchar_(stack_t **put, unsigned int line);
void pstr_(stack_t **put, unsigned int line);
void (*_opcode(char *tok, unsigned int line))(stack_t **, unsigned int);
void open_f(char **argc);

/* error functions */
void usage_err(void);
void file_err(char **argv);
void _instruction(char *tok, unsigned int line);
int _comment(char *tok, unsigned int line);
#endif

