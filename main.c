#include "monty.h"
/**
* main - Entry point
* @argc: argument count
* @argv: argument values
* Return: 0
*/
int main(int argc, char **argv)
{
	if (argc != 2)
	usage_err();
	open_f(argv);
	return (0);
}

