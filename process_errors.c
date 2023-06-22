#include "monty.h"

/**
 * swap_fail - error
 * @line_number: number of lines
 */

void swap_fail(unsigned int line_number)
{
	fprintf(stderr, SWAP_FAIL, line_number);
	free_all(1);
	exit(EXIT_FAILURE);
}


/**
 * error_pint - print error message when stack is empty
 * @line_number: number of lines
 */
void error_pint(unsigned int line_number)
{
	fprintf(stderr, PINT_FAIL, line_number);
	free_all(1);
	exit(EXIT_FAILURE);
}
/**
 * error_push - print error message for unkown instruction opcode
 * @line_number: number of lines
 */
void error_push(unsigned int line_number)
{
	fprintf(stderr, PUSH_FAIL, line_number);
	free_all(1);
	exit(EXIT_FAILURE);
}


/**
 * error_pop - print error message when stack is empty
 * @line_number: number of lines
 */
void error_pop(unsigned int line_number)
{
	fprintf(stderr, POP_FAIL, line_number);
	free_all(1);
	exit(EXIT_FAILURE);
}
