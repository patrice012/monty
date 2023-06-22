#include "monty.h"
#include "lists.h"


data_t data = DATA_INIT;

/**
 * monty - helper function for main function
 * @args: pointer to struct of arguments from main
 *
 * Description: opens and reads from the file
 * containing the opcodes, and calls the function
 * that will find the corresponding executing function
 */
void monty(args_t *args)
{
	size_t len = 0;
	int get = 0;
	void (*code_func)(stack_t **, unsigned int);

	process_file(args);
	while (1)
	{
		args->line_number++;
		get = getline(&(data.line), &len, data.fptr);
		if (get < 0)
			break;
		data.words = strtow(data.line);
		/*printf("data %s value %d\n", data.words[0], data.words[0][0]);*/
		if (data.words[0] == NULL || data.words[0][0] == '#')
		{
			free_all(0);
			continue;
		}
		code_func = get_func(data.words);
		if (!code_func)
			code_error(args->line_number);
		code_func(&(data.stack), args->line_number);
		free_all(0);
	}
	free_all(1);
}

/**
 * main - entry point for monty bytecode interpreter
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	args_t args;

	args.av = argv[1];
	args.ac = argc;
	args.line_number = 0;

	monty(&args);

	return (EXIT_SUCCESS);
}
