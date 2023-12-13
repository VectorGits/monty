#include "monty.h"

/**
 * parse_line - Parses a line of Monty bytecode and updates program state
 * @program_ptr: Pointer to the monty_program_t struct
 *
 * Description: This function takes a line from the Monty bytecode file,
 * extracts the opcode and its argument (if present), and updates the
 * program's state accordingly. If an error is found (e.g., invalid integer),
 * the function will print an error message and exit the program.
 */
void parse_line(monty_program_t *program_ptr)
{
	char *token;
	char *endptr;
	long arg;
	char *comment;

	comment = strchr(program_ptr->current_line, '#');
	if (comment != NULL)
	{
		*comment = '\0';
	}
	token = strtok(program_ptr->current_line, " \n\t");
	if (token == NULL)
	{
		program_ptr->current_opcode = NULL;
		return;
	}
	program_ptr->current_opcode = token;
	if (strcmp(program_ptr->current_opcode, "push") == 0)
	{
		token = strtok(NULL, " \n\t");
		if (token == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n",
				program_ptr->line_num);
			exit(EXIT_FAILURE);
		}
		arg = strtol(token, &endptr, 10);
		if (*endptr != '\0' || token == endptr)
		{
			fprintf(stderr, "L%d: usage: push integer\n",
				program_ptr->line_num);
			exit(EXIT_FAILURE);
		}
		program_ptr->current_arg = (int)arg;
	}
}

/**
 * execute_opcode - Executes the current opcode
 * @program_ptr: Pointer to the monty_program_t struct
 *
 * Description: This function checks the current opcode and executes the
 * corresponding function. If the opcode is NULL (indicating an empty line or
 * just whitespace), or if the opcode is unknown, it handles these cases
 * appropriately, including exiting the program with an error message if
 * an unknown instruction is encountered.
 */
void execute_opcode(monty_program_t *program_ptr)
{
	if (program_ptr->current_opcode == NULL)
		return;
	if (strcmp(program_ptr->current_opcode, "push") == 0)
		push_opcode(program_ptr);
	else if (strcmp(program_ptr->current_opcode, "pall") == 0)
		pall_opcode(program_ptr);
	else if (strcmp(program_ptr->current_opcode, "pint") == 0)
		pint_opcode(program_ptr);
	else if (strcmp(program_ptr->current_opcode, "pop") == 0)
		pop_opcode(program_ptr);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
			program_ptr->line_num, program_ptr->current_opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * free_stack - Frees a stack
 * @stack: Pointer to the top of the stack
 *
 * Description: This function iterates through a stack and frees
 * each element. The function continues until it has traversed
 * and freed the entire stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
