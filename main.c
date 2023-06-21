#include "monty.h"


global_v glob_var;

void call_function_error(char *line);
void process_input(char **lines);


/**
 * free_vglo - frees the global variables
 *
 * Return: no return
 */
void free_vglo(void)
{
	free_dlistint(glob_var.head);
	free(glob_var.buffer);
	/*fclose(glob_var.fd);*/
}


/**
 * init_global_var - initializes the global variables
 *
 * @fd: file descriptor
 * Return: no return
 */
void init_global_var(FILE *fd)
{
	glob_var.data_type = 1;
	glob_var.cont = 1;
	glob_var.arg = NULL;
	glob_var.head = NULL;
	glob_var.fd = fd;
	glob_var.buffer = NULL;
}

/**
 * check_input - checks if the file exists and if the file can
 * be opened
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: always 0
 */
int check_input(int argc)
{
	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return(EXIT_FAILURE);
	}
	return (0);
}

/**
 * main - main function
 * @argv: list of arguments
 * @argc: number of all argument
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	size_t size = 0;
	FILE *fd;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	if (check_input(argc) == EXIT_FAILURE)
			return (EXIT_FAILURE);

	if (process_file(argv[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	fd = glob_var.fd;
	init_global_var(fd);

	/*nlines = _getline(&glob_var.buffer, &size, fd);*/
	nlines = getline(&glob_var.buffer, &size, fd);
	while (nlines != -1)
	{
		process_input(lines);
		nlines = getline(&glob_var.buffer, &size, fd);
		glob_var.cont++;
	}

	/*free_vglo();*/
	return (0);
}

/**
 * process_input - execute input
 * @lines: array of data
 */

void process_input(char **lines)
{
	void (*func)(stack_t **stack, unsigned int line_number);
	char *opcode = NULL, *value = NULL;


	parse_instruction(glob_var.buffer, &opcode, &value);

	lines[0] = strtok(glob_var.buffer, " \t\n");
	if (lines[0] && lines[0][0] != '#')
	{
		func = get_func(lines[0]);
		if (!func)
			call_function_error(lines[0]);
		glob_var.arg = strtok(NULL, " \t\n");
		func(&glob_var.head, glob_var.cont);
	}
}

