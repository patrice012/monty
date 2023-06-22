#include "monty.h"

/**
 * process_file - updates file descriptor to read input from a file
 *
 * @args: data
 * Return: 0 on success, otherwise error code
 */
int process_file(args_t *args)
{
	if (args->ac != 2)
		call_function_error();
	if (access(args->av, R_OK) == -1)
		error_file(args);
	data.fptr = fopen(args->av, "r");
	if (!data.fptr)
		error_file(args);
	return (0);
}
