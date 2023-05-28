#include "monty.h"
int nums;
/**
 * open_f - function that opens the file
 * @argv: argument value
 */
void open_f(char **argv)
{
        void (*_func)(stack_t **, unsigned int);
        ssize_t line;
        FILE *ff;
        char *buff = NULL, *tok = NULL, command[1024];
        size_t length = 0;
        unsigned int line_counter = 1;
        stack_t *put = NULL;

        ff = fopen(argv[1], "r");
        if (ff == NULL)
                file_err(argv);
        while ((line = getline(&buff, &length, ff)) != -1)
        {
                tok = strtok(buff, "\n\t\r ");

                if (*tok == '\0')
                        continue;
                strcpy(command, tok);
                if (_comment(tok, line_counter) == 1)
                        continue;
                if (strcmp(tok, "push") == 0)
                {
                        tok = strtok(NULL, "\n\t\r ");
                        nums = atoi(tok);
                        _func = *_opcode(command, line_counter);
                        _func(&put, line_counter);
                }
                else
                {
                        _func = *_opcode(tok, line_counter);
                        _func(&put, line_counter);
                }
                line_counter++;
        }
        fclose(ff);

        if (buff != NULL)
                free(buff);
        free_(put);
}
int _comment(char *tok, unsigned int line)
{
        if (tok[0] == '#')
        {
                line++;
                return (1);
        }
        return (-1);
}

