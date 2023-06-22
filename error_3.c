#include "monty.h"


/**
 * malloc_fail - print error when malloc fail
 */

void malloc_fail(void)
{
	fprintf(stderr, MALLOC_FAIL);
	free_all(1);
	exit(EXIT_FAILURE);
}



/**
 * call_function_error - function fail error
 */
void call_function_error(void)
{
	/*fprintf(stderr, USAGE);*/
	fprintf(stderr, USAGE);
	exit(EXIT_FAILURE);
}

/**
 * code_error - unknow code
 * @line_number: number of lines
 */

void code_error(unsigned int line_number)
{
	fprintf(stderr, UNKNOWN, line_number, data.words[0]);
	free_all(1);
	exit(EXIT_FAILURE);
}


/**
 * error_file - print error message for file failures.
 * @args: data
 *
 */
void error_file(args_t *args)
{
	fprintf(stderr, FILE_ERROR, args->av);
	exit(EXIT_FAILURE);
}

/**
 * error_instruction - print error message for unkown instruction opcode
 *
 * @opcode: the unkown opcode
 *
 * Return: -1 on failure
 */
int error_instruction(UNUSED char *opcode)
{
	return (0);
}

