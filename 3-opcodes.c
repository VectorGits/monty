#include "monty.h"

/**
 * mod_opcode - Performs modulo operation on the second top and
 * top elements of the stack
 * @program_ptr: Pointer to the monty_program_t struct
 *
 * Description: This function performs a modulo operation on the second top
 * and top elements of the stack. It checks if the stack has at least two
 * elements and if the top element (the divisor) is not zero.
 * If any of these conditions are not met, it prints an error
 * message and exits the program. After the modulo operation, the top element
 * is removed from the stack.
 */
void mod_opcode(monty_program_t *program_ptr)
{
	stack_t *top, *second;

	if (program_ptr->stack == NULL || program_ptr->stack->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n",
			program_ptr->line_num);
		exit(EXIT_FAILURE);
	}
	top = program_ptr->stack;
	second = top->next;
	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n",
			program_ptr->line_num);
		exit(EXIT_FAILURE);
	}
	second->n %= top->n;
	program_ptr->stack = second;
	second->prev = NULL;
	free(top);
}
