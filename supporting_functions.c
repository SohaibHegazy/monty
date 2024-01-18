#include "monty.h"

/**
 * add_node_start - function to add node at the beginning of a linked list
 * @stack: pointer to the list head
 * @n: value of the new node
 *
 * Return: pointer to the new node
 */

stack_t *add_node_start(stack_t **stack, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;

	if (*stack == NULL)
		new->next = NULL;
	else
	{
		(*stack)->prev = new;
		new->next = *stack;
	}

	*stack = new;

	return (new);
}

/**
 * _is_int - function to check if string is integer
 * @string: the string to be checked
 *
 * Return: 1 if integer and 0 if not
 */

int _is_int(char *string)
{
	if (string == NULL || *string == '\0')
		return (0);

	if (*string == '+' || *string == '-')
		string++;

	while (*string != '\0')
	{
		if (*string < 48 || *string > 57)
			return (0);
		string++;
	}
	return (1);
}

