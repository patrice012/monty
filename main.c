#include "monty.h"
/*bus_t bus = {NULL, NULL, NULL, 0};*/


bus_t bus;



/**
 * init_global_var - initializes the global variables
 * Return: no return
 */
void init_global_var(void)
{

	bus.arg = NULL;
	bus.file = NULL;
	bus.content = NULL;
	bus.counter = 0;
	bus.lifi = 0;
}


/**
 * check_input - checks if the file exists and if the file can
 * be opened
 *
 * @argc: argument count
 * Return: always 0
 */
int check_input(int argc)
{
	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	return (0);
}


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

	bus.file = fopen(file, "r");
	if (!bus.file)
	{
		error_file(file);
		return (EXIT_FAILURE);
	}
	return (0);
}



/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *content;
	/*FILE *file;*/
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	/*unsigned int counter = 0;*/

	init_global_var();
	if (check_input(argc) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (process_file(argv[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, bus.file);
		bus.content = content;
		bus.counter++;
		if (read_line > 0)
		{
			execute(content, &stack, bus.file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(bus.file);
return (0);
}
