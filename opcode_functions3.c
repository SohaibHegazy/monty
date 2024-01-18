#include "monty.h"

/**
 * mod_func - function to get modulus of second element of a stack by the top
 * @stack: pointer to the stack top
 * @line_num: line number
 *
 * Return: void
 */

void mod_func(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);

		free_stack(*stack);
		free(var.my_line);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);

		free(var.my_line);
		exit(EXIT_FAILURE);
	}
	else
	{
		*stack = (*stack)->next;
		(*stack)->n %= temp->n;

		free(temp);
	}
}

