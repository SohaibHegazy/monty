#include "monty.h"

/**
 * add_func - function to add the top two elements of a stack
 * @stack: pointer to the stack top
 * @line_num: line number
 *
 * Return: void
 */

void add_func(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);

		free_stack(*stack);
		free(var.my_line);
		exit(EXIT_FAILURE);
	}
	else
	{
		*stack = (*stack)->next;
		(*stack)->n += temp->n;

		free(temp);
	}
}

/**
 * nop_func - doesn't do anything
 * @stack: pointer to the stack top
 * @line_num: line number
 *
 * Return: void
 */

void nop_func(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}

/**
 * sub_func - function to sub the top element of a stack from the second
 * @stack: pointer to the stack top
 * @line_num: line number
 *
 * Return: void
 */

void sub_func(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);

		free_stack(*stack);
		free(var.my_line);
		exit(EXIT_FAILURE);
	}
	else
	{
		*stack = (*stack)->next;
		(*stack)->n -= temp->n;

		free(temp);
	}
}

/**
 * div_func - function to divide the second element of a stack by the top
 * @stack: pointer to the stack top
 * @line_num: line number
 *
 * Return: void
 */

void div_func(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);

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
		(*stack)->n /= temp->n;

		free(temp);
	}
}

/**
 * mul_func - function to multiply the top two elements of a stack
 * @stack: pointer to the stack top
 * @line_num: line number
 *
 * Return: void
 */

void mul_func(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);

		free_stack(*stack);
		free(var.my_line);
		exit(EXIT_FAILURE);
	}
	else
	{
		*stack = (*stack)->next;
		(*stack)->n *= temp->n;

		free(temp);
	}
}
