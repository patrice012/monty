#include "monty.h"


global_v glob_var;


/**
 * free_vglo - frees the global variables
 *
 * Return: no return
 */
void free_vglo(void)
{
	free_dlistint(glob_var.head);
	free(glob_var.buffer);
	fclose(glob_var.fd);
}

/**
 * start_vglo - initializes the global variables
 *
 * @fd: file descriptor
 * Return: no return
 */
void start_vglo(FILE *fd)
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
 * Return: file struct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - main function
 * @argv: list of arguments
 * @argc: number of all argument
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	fd = check_input(argc, argv);
	start_vglo(fd);
	nlines = getline(&glob_var.buffer, &size, fd);
	printf("line: %s\n", glob_var.buffer);
	while (nlines != -1)
	/*while (fgets(&glob_var.buffer, &size, fd) != NULL)*/
	{
		lines[0] = strtok(glob_var.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_func(lines[0]);
			if (!f)
			{
				fprintf(stderr, "L%u: ", glob_var.cont);
				fprintf(stderr, "unknown instruction %s\n", lines[0]);
				free_vglo();
				exit(EXIT_FAILURE);
			}
			glob_var.arg = strtok(NULL, " \t\n");
			f(&glob_var.head, glob_var.cont);
		}
		nlines = getline(&glob_var.buffer, &size, fd);
		glob_var.cont++;
	}

	free_vglo();

	return (0);
}

