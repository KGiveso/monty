#include "monty.h"
/**
 * usage_err - function that prints the error for usage of the file
 */
void usage_err(void)
{
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
}
/**
 * file_err - function that prints the error for the file
 * @argv: argument string value
 */
void file_err(char **argv)
{
        char *name = argv[1];

        fprintf(stderr, "Error: Can't open file %s\n", name);
        exit(EXIT_FAILURE);
}
/**
 * invalid_instruction - function that prints the error for invalid opcode.
 * @tok: token
 * @line: line
 */
void _instruction(char *tok, unsigned int line)
{
        fprintf(stderr, "L%u: unknown instruction %s\n", line, tok);
        exit(EXIT_FAILURE);
}

