#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct var_s - struct to pass info globally
 * @my_arg: the argument
 * @my_file: pointer to the monty file
 * @my_line: input line
 *
 * Description: struct that passes info globally
 */

typedef struct var_s
{
	char *my_arg;
	FILE *my_file;
	char *my_line;
} var_t;

extern var_t var;

/* execute file functions */

void get_func(char *opcode, stack_t **stack, unsigned int line_number);
void exec(stack_t **stack);
void free_stack(stack_t *stack);

/* opcode_functions1 file functions */

void push_func(stack_t **stack, unsigned int line_number);
void pall_func(stack_t **stack, unsigned int line_number);
void pint_func(stack_t **stack, unsigned int line_number);
void pop_func(stack_t **stack, unsigned int line_number);
void swap_func(stack_t **stack, unsigned int line_number);

/* opcode_functions2 file functions */

void add_func(stack_t **stack, unsigned int line_number);
void nop_func(stack_t **stack, unsigned int line_number);
void sub_func(stack_t **stack, unsigned int line_number);
void div_func(stack_t **stack, unsigned int line_number);
void mul_func(stack_t **stack, unsigned int line_number);

/* opcode_functions3 file functions */

void mod_func(stack_t **stack, unsigned int line_number);

/* supporting_functions file functions */

stack_t *add_node_start(stack_t **stack, const int n);
int _is_int(char *string);




#endif
