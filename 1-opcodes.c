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

/**
 * pop_opcode - Pops the top element off the stack
 * @program_ptr: Pointer to the monty_program_t struct
 *
 * Description: This function removes the top element from the stack.
 * If the stack is empty, it prints an error message and exits the program.
 * It handles the removal and proper memory deallocation of the top element.
 */
void pop_opcode(monty_program_t *program_ptr)
{
	stack_t *temp;

	if (program_ptr->stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n",
			program_ptr->line_num);
		exit(EXIT_FAILURE);
	}
	temp = program_ptr->stack;
	program_ptr->stack = program_ptr->stack->next;
	if (program_ptr->stack != NULL)
	{
		program_ptr->stack->prev = NULL;
	}
	free(temp);
}

/**
 * swap_opcode - Swaps the top two elements of the stack
 * @program_ptr: Pointer to the monty_program_t struct
 *
 * Description: This function swaps the top two elements on the stack.
 * If the stack does not have at least two elements, it prints an error
 * message and exits the program. It handles the re-linking of the stack
 * nodes to achieve the swap.
 */
void swap_opcode(monty_program_t *program_ptr)
{
	stack_t *first, *second;

	if (program_ptr->stack == NULL || program_ptr->stack->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			program_ptr->line_num);
		exit(EXIT_FAILURE);
	}
	first = program_ptr->stack;
	second = program_ptr->stack->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	program_ptr->stack = second;
}