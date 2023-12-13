#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/* Data Structures */
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
 * struct monty_program_s - Structure for Monty program's information
 * @stack: Pointer to the top of the stack
 * @line_num: Current line number in the script
 * @mode: Mode of operation (0 for stack, 1 for queue)
 * @script_file: File pointer to the Monty bytecode file
 * @current_line: Current line from the file
 * @current_opcode: Current opcode being executed
 * @current_arg: Current argument for the opcode, if applicable
 * @error_flag: Flag to indicate an error
 *
 * Description: Holds all the necessary information to manage a Monty
 * bytecode script, including the state of the stack, the current
 * line and opcode being processed, and the mode of operation.
 */
typedef struct monty_program_s
{
	stack_t *stack;
	unsigned int line_num;
	int mode;
	FILE *script_file;
	char *current_line;
	char *current_opcode;
	int current_arg;
	bool error_flag;
} monty_program_t;

extern monty_program_t program;
extern monty_program_t *program_ptr;
extern char **environ;

/* core.c */
void parse_line(monty_program_t *program_ptr);
void execute_opcode(monty_program_t *program_ptr);
void free_stack(stack_t *stack);

/* opcodes.c */
void push_opcode(monty_program_t *program_ptr);
void pall_opcode(monty_program_t *program_ptr);
void pint_opcode(monty_program_t *program_ptr);

#endif /* MONTY_H */
