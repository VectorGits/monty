# Monty Interpreter

## Project Overview

This project, engineered by David Oluremi, involves the creation of an interpreter for Monty ByteCodes files, a scripting language compiled into byte codes, similar to Python. The key focus is on implementing stacks and queues using C programming language, adhering to the LIFO (Last In, First Out) and FIFO (First In, First Out) principles.

## Solo Team Member

- **David Oluremi**

## Data Structures

Below are the data structures used in this project.
  ```c
  typedef struct stack_s
  {
      int n;
      struct stack_s *prev;
      struct stack_s *next;
  } stack_t;

  typedef struct instruction_s
  {
      char *opcode;
      void (*f)(stack_t **stack, unsigned int line_number);
  } instruction_t;

  typedef enum
  {
      MODE_STACK,
      MODE_QUEUE
  } stack_mode_t;

  typedef struct monty_program_s
  {
     stack_t *stack;
     unsigned int line_num;
     FILE *script_file;
     char *current_line;
     char *current_opcode;
     int current_arg;
     stack_mode_t mode;
  } monty_program_t;
  ```

## Monty ByteCodes Files

- **File Extension**: `.m`
- **Structure**: One instruction per line, spaces before and after opcodes and arguments are permissible. Blank lines and text after opcodes/arguments are ignored.

## Usage

- **Command**: `./monty file`
  - `file`: Path to the Monty byte code file.
- **Error Handling**:
  - Incorrect usage: `USAGE: monty file`
  - File opening issues: `Error: Can't open file <file>`
  - Invalid instruction: `L<line_number>: unknown instruction <opcode>`
  - Memory allocation issues: `Error: malloc failed`

## Compilation and Output

- **Compilation**: `$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty`
- **Output**: Print on stdout, errors on stderr.

## Detailed Features and Functional Capabilities

### 0. push, pall
- **Functionality**: Implement the `push` and `pall` opcodes.
- **push opcode**: Pushes an element to the stack.
  - **Usage**: `push <int>` where `<int>` is an integer.
  - **Error Handling**: If `<int>` is not an integer or no argument is given, prints `L<line_number>: usage: push integer`.
- **pall opcode**: Prints all values on the stack from the top.
  - **Usage**: `pall`
  - **Behavior**: Does not print anything if the stack is empty.

### 1. pint
- **Functionality**: Implement the `pint` opcode.
- **pint opcode**: Prints the value at the top of the stack.
  - **Usage**: `pint`
  - **Error Handling**: If the stack is empty, prints `L<line_number>: can't pint, stack empty`.

### 2. pop
- **Functionality**: Implement the `pop` opcode.
- **pop opcode**: Removes the top element of the stack.
  - **Usage**: `pop`
  - **Error Handling**: If the stack is empty, prints `L<line_number>: can't pop an empty stack`.

### 3. swap
- **Functionality**: Implement the `swap` opcode.
- **swap opcode**: Swaps the top two elements of the stack.
  - **Usage**: `swap`
  - **Error Handling**: If the stack has less than two elements, prints `L<line_number>: can't swap, stack too short`.

### 4. add
- **Functionality**: Implement the `add` opcode.
- **add opcode**: Adds the top two elements of the stack.
  - **Usage**: `add`
  - **Behavior**: Stores the result in the second top element and removes the top element.
  - **Error Handling**: If the stack has less than two elements, prints `L<line_number>: can't add, stack too short`.

### 5. nop
- **Functionality**: Implement the `nop` opcode.
- **nop opcode**: Does not perform any operation.
  - **Usage**: `nop`

### 6. sub
- **Functionality**: Implement the `sub` opcode.
- **sub opcode**: Subtracts the top element of the stack from the second top element.
  - **Usage**: `sub`
  - **Error Handling**: If the stack has less than two elements, prints `L<line_number>: can't sub, stack too short`.

### 7. div
- **Functionality**: Implement the `div` opcode.
- **div opcode**: Divides the second top element of the stack by the top element.
  - **Usage**: `div`
  - **Error Handling**:
    - If the stack has less than two elements, prints `L<line_number>: can't div, stack too short`.
    - If the top element is 0, prints `L<line_number>: division by zero`.

### 8. mul
- **Functionality**: Implement the `mul` opcode.
- **mul opcode**: Multiplies the second top element with the top element of the stack.
  - **Usage**: `mul`
  - **Error Handling**: If the stack has less than two elements, prints `L<line_number>: can't mul, stack too short`.

### 9. mod
- **Functionality**: Implement the `mod` opcode.
- **mod opcode**: Computes the remainder of the division of the second top element by the top element.
  - **Usage**: `mod`
  - **Error Handling**: 
    - If the stack has less than two elements, prints `L<line_number>: can't mod, stack too short`.
    - If the top element is 0, prints `L<line_number>: division by zero`.

### 10. comments
- **Functionality**: Implement handling for comments.
- **Behavior**: Lines starting with `#` are treated as comments.

### 11. pchar
- **Functionality**: Implement the `pchar` opcode.
- **pchar opcode**: Prints the char at the top of the stack.
  - **Usage**: `pchar`
  - **Error Handling**: 
    - If the value is not in the ASCII range, prints `L<line_number>: can't pchar, value out of range`.
    - If the stack is empty, prints `L<line_number>: can't pchar, stack empty`.

### 12. pstr
- **Functionality**: Implement the `pstr` opcode.
- **pstr opcode**: Prints the string starting from the top of the stack.
  - **Usage**: `pstr`
  - **Behavior**: Stops printing when the stack is over, the value is 0, or not in the ASCII table.

### 13. rotl
- **Functionality**: Implement the `rotl` opcode.
- **rotl opcode**: Rotates the stack to the top.
  - **Usage**: `rotl`
  - **Behavior**: The top element becomes the last one, and the second top element becomes the first one.

### 14. rotr
- **Functionality**: Implement the `rotr` opcode.
- **rotr opcode**: Rotates the stack to the bottom.
  - **Usage**: `rotr`
  - **Behavior**: The last element of the stack becomes the top element.

### 15. stack, queue
- **Functionality**: Implement the `stack` and `queue` opcodes.
- **stack opcode**: Sets format to stack (LIFO).
  - **Usage**: `stack`
- **queue opcode**: Sets format to queue (FIFO).
  - **Usage**: `queue`
  - **Behavior**: Switches between stack and queue modes.

### 16. Brainf*ck
- **Task**: Write a Brainf*ck script to print "School" followed by a new line.
- **Directory**: `bf`
- **File**: `1000-school.bf`

### 17. Add two digits
- **Task**: Add two digits given by the user and print the result.
- **Directory**: `bf`
- **File**: `1001-add.bf`

### 18. Multiplication
- **Task**: Multiply two digits given by the user and print the result.
- **Directory**: `bf`
- **File**: `1002-mul.bf`

### 19. Multiplication level up
- **Task**: Multiply two digits given by the user and print the result, followed by a new line.
- **Directory**: `bf`
- **File**: `1003-mul.bf`

## Acknowledgments

Special acknowledgment goes to my mentors and the educational cadre at the ALX program for their invaluable support and guidance. A big shoutout to all contributors and colleagues who have written code, submitted issues, or provided indispensable feedback.

## Frequently Asked Questions (FAQs)

- **Q: How do I compile the code?**
  - **A:** Execute `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`.

- **Q: What commands are currently supported?**
  - **A:** Refer to the "Detailed Features and Functional Capabilities" section of the README for a comprehensive list of supported commands and features.

- **Q: I've found a bug, where should I report it?**
  - **A:** Please file an issue on the GitHub project page.

- **Q: Does the shell support scripting?**
  - **A:** Yes, the shell can execute commands from a file passed as a command-line argument.

- **Q: How can I reach you?**
  - **A:** Reach me via:
	   - LinkedIn: [David Oluremi](https://www.linkedin.com/in/vect0r/)
	   - Twitter: [Vector Twits](https://twitter.com/Vector_twits)
