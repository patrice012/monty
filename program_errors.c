#include "monty.h"


/**
 * error_sub_fail - print error message when division by zero
 * @line_number: number of lines
 */
void error_sub_fail(unsigned int line_number)
{
	fprintf(stderr, SUB_FAIL, line_number);
	free_all(1);
	exit(EXIT_FAILURE);
}

/**
 * error_div_fail - print error message when division by zero
 * @line_number: number of lines
 */
void error_div_fail(unsigned int line_number)
{
	fprintf(stderr, DIV_FAIL, line_number);
	free_all(1);
	exit(EXIT_FAILURE);
}

/**
 * error_zero_division - print error message when division by zero
 * @line_number: number of lines
 */
void error_zero_division(unsigned int line_number)
{
	fprintf(stderr, DIV_ZERO, line_number);
	free_all(1);
	exit(EXIT_FAILURE);
}

/**
 * error_mul_fail - print error message when division by zero
 * @line_number: number of lines
 */
void error_mul_fail(unsigned int line_number)
{
	fprintf(stderr, MUL_FAIL, line_number);
	free_all(1);
	exit(EXIT_FAILURE);
}


/**
 * error_mod_fail - print error message when division by zero
 * @line_number: number of lines
 */
void error_mod_fail(unsigned int line_number)
{
	fprintf(stderr, MOD_FAIL, line_number);
	free_all(1);
	exit(EXIT_FAILURE);
}

/**
 * call_function_error - fail to call function
 */


