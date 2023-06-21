#include "monty.h"

/**
 * error_malloc - print error message when malloc can't allocate memory anymore
 */
void error_malloc(void)
{
	print_err("Error: malloc failed\n");
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
	unsigned int line_number = glob_var.cont;

	print_err("L");
	print_err(_itoa(line_number));
	print_err(": can't ");
	print_err(opcode);
	if (strcmp(opcode, "pchar") == 0)
		print_err(", stack empty\n");
	else
		print_err(", stack too short\n");
	return (-1);
}

/**
 * error_div_zero - print error message when division by zero
 *
 * Return: -1
 */
int error_div_zero(void)
{
	unsigned int line_number = glob_var.cont;

	print_err("L");
	print_err(_itoa(line_number));
	print_err(": division by zero\n");
	return (-1);
}

/**
 * error_pchar - print error message when value is not in ASCII table
 *
 * Return: -1
 */
int error_pchar(void)
{
	unsigned int line_number = glob_var.cont;

	print_err("L");
	print_err(_itoa(line_number));
	print_err(": can't pchar, value out of range\n");
	return (-1);
}


/**
 * call_function_error - fail to call function
 * @line: line message
 */

void call_function_error(char *line)
{
	fprintf(stderr, "L%u: ", glob_var.cont);
	fprintf(stderr, "unknown instruction %s\n", line);
	/*free_vglo();*/
	exit(EXIT_FAILURE);
}
