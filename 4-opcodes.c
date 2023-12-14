#include "monty.h"

/**
 * stack_opcode - Sets the mode of the program to stack (LIFO)
 * @program_ptr: Pointer to the monty_program_t struct
 *
 * Description: This function sets the mode of the program to stack, which
 * means the program will operate in Last In First Out (LIFO) mode.
 */
void stack_opcode(monty_program_t *program_ptr)
{
	program_ptr->mode = 0;
}

/**
 * queue_opcode - Sets the mode of the program to queue (FIFO)
 * @program_ptr: Pointer to the monty_program_t struct
 *
 * Description: This function sets the mode of the program to queue, which
 * means the program will operate in First In First Out (FIFO) mode.
 */
void queue_opcode(monty_program_t *program_ptr)
{
	program_ptr->mode = 1;
}
