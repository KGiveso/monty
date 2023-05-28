#include "monty.h"
/**
 * _opcode - function pointer that takes argument of function in struct
 * @tok: token
 * @line: line
 * Return(NULL);
 */
void (*_opcode(char *tok, unsigned int line))(stack_t **, unsigned int)
{
        int h;
        instruction_t op[] = {
                {"push", push_},
                {"pop", pop_},
                {"pint", pint_},
                {"pall", pall_},
                {"swap", swap_},
                {"add", add_},
                {"sub", sub_},
                {"div", div_},
                {"mul", mul_},
                {"mod", mod_},
                {"nop", nop_},
                {"pchar", pchar_},
                {"pstr", pstr_},
                {"rotl", rotl_},
                {"rotr", rotr_},
                {NULL, NULL}
        };
        for (h = 0; op[h].opcode != NULL; h++)
        {
                if (strcmp(tok, op[h].opcode) == 0)
                        return (op[h].f);
        }
        _instruction(tok, line);
        return (NULL); /*return NULL*/
}

