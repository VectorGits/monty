#include "monty.h"

/**
 * push_opcode - Pushes a value onto the stack
 * @program_ptr: Pointer to the monty_program_t struct
 *
 * Description: This function creates a new stack node and pushes it onto
 * the stack. It handles the allocation of the new node and updates the
 * stack pointer in the program structure. The function also handles errors
 * in memory allocation and operates differently based on the mode of the
 * program (stack or queue).
 */
void push_opcode(monty_program_t *program_ptr)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = program_ptr->current_arg;
	if (program_ptr->mode == 0)
	{
		new_node->prev = NULL;
		new_node->next = program_ptr->stack;
		if (program_ptr->stack != NULL)
		{
			program_ptr->stack->prev = new_node;
		}
		program_ptr->stack = new_node;
	}
	else
	{
		/* If your implementation supports queue mode, handle it here */
	}
}

/**
 * pall_opcode - Prints all the values on the stack
 * @program_ptr: Pointer to the monty_program_t struct
 *
 * Description: This function traverses through the stack starting
 * from the top and prints each element's value. It continues until
 * it has traversed the entire stack.
 */
void pall_opcode(monty_program_t *program_ptr)
{
	stack_t *current_node = program_ptr->stack;

	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}

/**
 * pint_opcode - Prints the value at the top of the stack
 * @program_ptr: Pointer to the monty_program_t struct
 *
 * Description: This function prints the value at the top of the stack.
 * If the stack is empty, it prints an error message and exits the program.
 */
void pint_opcode(monty_program_t *program_ptr)
{
	if (program_ptr->stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n",
			program_ptr->line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", program_ptr->stack->n);
}
