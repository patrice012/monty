#include "monty.h"

/**
 * process_file - updates file descriptor to read input from a file
 *
 * @file: the path to the file
 * Return: 0 on success, otherwise error code
 */
int process_file(char *file)
{
	if (access(file, R_OK) == -1)
	{
		error_file(file);
		return (EXIT_FAILURE);
	}

	glob_var.fd = fopen(file, "r");
	if (!glob_var.fd)
	{
		error_file(file);
		return (EXIT_FAILURE);
	}
	return (0);
}
