#include "monty.h"

/**
 * add_opcode - Adds the top two elements of the stack
 * @program_ptr: Pointer to the monty_program_t struct
 *
 * Description: This function adds the top two elements of the stack.
 * If the stack does not have at least two elements, it prints an error
 * message and exits the program. It performs the addition and then removes
 * the top element from the stack.
 */
void add_opcode(monty_program_t *program_ptr)
{
	stack_t *top, *second;

	if (program_ptr->stack == NULL || program_ptr->stack->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
			program_ptr->line_num);
		exit(EXIT_FAILURE);
	}
	top = program_ptr->stack;
	second = top->next;
	second->n += top->n;
	program_ptr->stack = second;
	second->prev = NULL;
	free(top);
}

/**
 * nop_opcode - Does nothing
 * @program_ptr: Pointer to the monty_program_t struct
 *
 * Description: This function is a no-operation function. It is designed
 * to do nothing and is typically used as a placeholder or to avoid an
 * unused parameter warning.
 */
void nop_opcode(monty_program_t *program_ptr)
{
	(void)program_ptr;
}
