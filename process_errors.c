#include "monty.h"

/**
 * error_file - print error message for file failures.
 *
 * @file: file name.
 */
void error_file(char *file)
{
	print_err("Error: Can't open file ");
	print_err(file);
	print_err("\n");
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
	unsigned int line_number = glob_var.cont;
	char *s = _itoa(line_number);

	print_err("L");
	print_err(s);
	print_err(": unknown instruction ");
	print_err(opcode);
	print_err("\n");

	free(s);
	return (-1);
}


/**
 * error_pint - print error message when stack is empty
 */
void error_pint(void)
{
	unsigned int line_number = glob_var.cont;
	char *s = _itoa(line_number);

	print_err("L");
	print_err(s);
	print_err(": can't pint, stack empty\n");

	free(s);
}

/**
 * error_push_value - print error message for unkown instruction opcode
 */
void error_push_value(void)
{
	unsigned int line_number = glob_var.cont;
	char *s = _itoa(line_number);

	print_err("L");
	print_err(s);
	print_err(": usage: push integer\n");
	free(s);
}


/**
 * error_pop - print error message when stack is empty
 */
void error_pop(void)
{
	unsigned int line_number = glob_var.cont;

	print_err("L");
	print_err(_itoa(line_number));
	print_err(": can't pop an empty stack\n");
}
