#include "monty.h"

/* global variables*/
int line_number = 1;
int format = STACK;
stack_t *list_head = NULL;
stack_t *list_tail = NULL;

/* helper functions */
int run_instruction(char *line_buffer);

/**
 * main - entry point to monty
 *
 * @argc: argument count
 * @argv: argument list
 *
 * Return: int
 */
int main(int argc, char *argv[])
{
	int fd, rn = 0;
	size_t line_size;
	char *line_buffer = NULL;

	if (argc != 2)
	{
		print_err("USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	if (process_file(argv[1], &fd) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (true)
	{
		if (_getline(&line_buffer, &line_size, fd) != -1)
		{
			if (rn != EXIT_FAILURE && run_instruction(line_buffer) == -1)
				rn = EXIT_FAILURE;
			line_number++;
		}
		else
			break;
	}

	free(line_buffer);
	free_list();
	close(fd);
	return (rn);
}

/**
 * run_instruction - parses and executes the instruction
 *
 * @line_buffer: string that contains the instruction details
 *
 * Return: 0 on success, -1 on failure
 */
int run_instruction(char *line_buffer)
{
	int rn = 0;
	char *opcode = NULL, *value = NULL;

	parse_instruction(line_buffer, &opcode, &value);

	if (opcode == NULL)
		return (0);

	if (_strcmp(opcode, "push") == 0)
		rn = op_push(value);
	else if (_strcmp(opcode, "pall") == 0 || _strcmp(opcode, "pint") == 0 ||
		_strcmp(opcode, "pchar") == 0 || _strcmp(opcode, "pstr") == 0)
		rn = print_operations(opcode);
	else if (_strcmp(opcode, "pop") == 0)
		rn = op_pop();
	else if (_strcmp(opcode, "swap") == 0)
		rn = op_swap();
	else if (_strcmp(opcode, "add") == 0 || _strcmp(opcode, "sub") == 0 ||
		_strcmp(opcode, "div") == 0 || _strcmp(opcode, "mul") == 0 ||
		_strcmp(opcode, "mod") == 0)
		rn = math_operations(opcode);
	else if (_strcmp(opcode, "nop") == 0 || opcode[0] == '#')
		rn = 0;
	else if (_strcmp(opcode, "rotr") == 0 || _strcmp(opcode, "rotl") == 0)
		rn = rotation_operations(opcode);
	else if (_strcmp(opcode, "queue") == 0 || _strcmp(opcode, "stack") == 0)
		rn = switch_format(opcode);
	else
		rn = error_instruction(opcode);

	free(opcode);
	if (value != NULL)
		free(value);

	return (rn);
}
