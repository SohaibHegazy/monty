#include "monty.h"

var_t var;

/**
 * main - entry point of the program
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 if success
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

		if (argc != 2)
		{
			fprintf(stderr, "USAGE: monty file\n");
			exit(EXIT_FAILURE);
		}

	var.my_file = fopen(argv[1], "r");

	if (var.my_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	exec(&stack);
	fclose(var.my_file);
	free(var.my_line);
	free_stack(stack);
	exit(EXIT_SUCCESS);
}
