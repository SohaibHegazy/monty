#include "monty.h"


/**
 * push_func - function to push into stack
 * @stack: pointer to the stack top
 * @line_num: ine number
 *
 * Return: void
 */

void push_func(stack_t **stack, unsigned int line_num)
{
	int n = 0;
	stack_t *node = NULL;

	if (var.my_arg != NULL && _is_int(var.my_arg))
	{
		n = atoi(var.my_arg);
		node = add_node_start(stack, n);

		if (node == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_stack(*stack);
			fclose(var.my_file);
			free(var.my_line);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		free_stack(*stack);
		fclose(var.my_file);
		free(var.my_line);
		exit(EXIT_FAILURE);
	}
}

/**
 * pall_func - function to print all elements of the stack
 * @stack: pointer to stack top
 * @line_num: line number
 *
 * Return: void
 */

void pall_func(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;


	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
		(void)line_num;
	}
}

/**
 * pint_func - function to print the top of stack
 * @stack: pointer to stack top
 * @line_num: line number
 *
 * Return: void
 */

void pint_func(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		free_stack(*stack);
		free(var.my_line);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}

/**
 * pop_func - function to pop top of stack
 * @stack: pointer to stack top
 * @line_num: line number
 *
 * Return: void
 */

void pop_func(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);

		free_stack(*stack);
		free(var.my_line);
		exit(EXIT_FAILURE);
	}
	else
	{
		*stack = (*stack)->next;
		free(temp);

		if (*stack != NULL)
			(*stack)->prev = NULL;
	}
}

/**
 * swap_func - function to swap two top elements of a stack
 * @stack: pointer to stack top
 * @line_num: line number
 *
 * Return: void
 */

void swap_func(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);

		free_stack(*stack);
		free(var.my_line);
		exit(EXIT_FAILURE);
	}
	else
	{
		*stack = (*stack)->next;

		temp->prev = *stack;
		(*stack)->prev = NULL;

		if ((*stack)->next != NULL)
			(*stack)->next->prev = temp;

		temp->next = (*stack)->next;
		(*stack)->next = temp;
	}
}
