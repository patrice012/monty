#include "monty.h"

/**
 * error_file - print error message for file failures.
 *
 * @file: file name.
 */
void error_file(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
}

/**
 * error_instruction - print error message for unkown instruction opcode
 *
 * @opcode: the unkown opcode
 *
 * Return: -1 on failure
 */
int error_instruction(char *opcode)
{
	unsigned int line_number = bus.counter;
	char *s = _itoa(line_number);

	fprintf(stderr, "L%s: unknown instruction\n", opcode);
	free(s);
	return (-1);
}


/**
 * error_pint - print error message when stack is empty
 */
void error_pint(void)
{
	unsigned int line_number = bus.counter;
	char *s = _itoa(line_number);

	fprintf(stderr, "L%s: can't pint, stack empty\n", s);
	free(s);
}

/**
 * error_push_value - print error message for unkown instruction opcode
 */
void error_push_value(void)
{
	unsigned int line_number = bus.counter;
	char *s = _itoa(line_number);

	fprintf(stderr, "L%s: usage: push integer\n", s);
	free(s);
}


/**
 * error_pop - print error message when stack is empty
 */
void error_pop(void)
{
	unsigned int line_number = bus.counter;

	fprintf(stderr, "L%s: can't pop an empty stack\n", _itoa(line_number));
}
