#include "monty.h"


/**
 * get_func - function to get the function based on the opcode
 * @opcode: pointer to opcode
 * @stack: pointer to stack head
 * @line_number: line number
 *
 * Return: void
 */

void get_func(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t instruct[] = {
		{"push", push_func},
		{"pall", pall_func},
		{"pint", pint_func},
		{"pop", pop_func},
		{"swap", swap_func},
		{"add", add_func},
		{"nop", nop_func},
		{"sub", sub_func},
		{"div", div_func},
		{"mul", mul_func},
		{"mod", mod_func},
		{NULL, NULL}
	};

	for (i = 0; instruct[i].opcode != NULL; i++)
	{
		if (strcmp(instruct[i].opcode, opcode) == 0)
		{
			instruct[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	free_stack(*stack);
	fclose(var.my_file);
	free(var.my_line);

	exit(EXIT_FAILURE);
}


/**
 * exec - function to execute the selected function
 * @stack: pointer to the stack head
 *
 * Return: void
 */

void exec(stack_t **stack)
{

	size_t len = 0;
	ssize_t bytes;
	unsigned int line_num = 0;
	char *opcode = NULL;

	while ((bytes = getline(&var.my_line, &len, var.my_file)) != -1)
	{
		line_num++;
		opcode = strtok(var.my_line, " \t\r\n\a");
		var.my_arg = strtok(NULL, " \n\t");

		if (opcode == NULL || *opcode == '#')
			continue;
		get_func(opcode, stack, line_num);
	}
}

/**
 * free_stack - function to free the stack
 * @stack: pointer to the stack head
 *
 * Return: void
 */

void free_stack(stack_t *stack)
{
	stack_t *temp;

	temp = stack;

	while (temp)
	{
		stack = stack->next;
		free(temp);
		temp = stack;
	}
}
