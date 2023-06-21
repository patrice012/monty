#include "monty.h"

/**
 * error_malloc - print error message when malloc can't allocate memory anymore
 */
void error_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * error_short_stack - print error message when stack is too short
 *
 * @opcode: opcode
 *
 * Return: -1
 */
int error_short_stack(char *opcode)
{
	unsigned int line_number = bus.counter;
	char *msg;

	if (strcmp(opcode, "pchar") == 0)
		msg = ", stack empty";
	else
		msg = ", stack too short";
	fprintf(stderr, "L%s: can't %s %s\n", _itoa(line_number), opcode, msg);
	return (-1);
}

/**
 * error_div_zero - print error message when division by zero
 *
 * Return: -1
 */
int error_div_zero(void)
{
	unsigned int line_number = bus.counter;

	fprintf(stderr, "L%s: division by zero\n", _itoa(line_number));
	return (-1);
}

/**
 * error_pchar - print error message when value is not in ASCII table
 *
 * Return: -1
 */
int error_pchar(void)
{
	unsigned int line_number = bus.counter;

	fprintf(stderr, "L%s: can't pchar, value out of range\n", _itoa(line_number));
	return (-1);
}


/**
 * call_function_error - fail to call function
 * @line: line message
 * @line: line message
 */

void call_function_error(char *line)
{
	fprintf(stderr, "L%u: ", bus.counter);
	fprintf(stderr, "unknown instruction %s\n", line);
	/*free_vglo();*/
	exit(EXIT_FAILURE);
}
