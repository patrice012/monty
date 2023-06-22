#include "monty.h"
#include "lists.h"

/**
 * get_len - get the length of array
 * @size: array size
 * @uniq_size: data size
 * Return: int => the size of array
 */

int get_len(ssize_t size, int uniq_size)
{
	return (size / uniq_size);
}

/**
 * get_func - selects the right function
 * @parsed: line from the bytecode file passed to main
 *
 * Return: pointer to the selected function, or NULL on failure
 */
void (*get_func(char **parsed))(stack_t **, unsigned int)
{
	int codes, i;

	instruction_t func_arr[] = {
		{"push", push_handler},
		{"pall", pall_handler},
		{"pint", pint_handler},
		{"pop", pop_handler},
		{"swap", swap_handler},
		{"add", add_handler},
		{"nop", nop_handler},
		{"sub", sub_handler},
		{"div", div_handler},
		{"mul", mul_handler},
		{"mod", mod_handler},
		{"pchar", pchar_handler},
		{"pstr", pstr_handler},
		{"rotl", rotl_handler},
		{"rotr", rotr_handler},
		{"stack", stack_handler},
		{"queue", queue_handler},
		{NULL, NULL}
	};

	codes = get_len(sizeof(func_arr), sizeof(func_arr[0]));

	for (i = 0; i < codes && func_arr[i].opcode; i++)
	{
		if (strcmp(func_arr[i].opcode, parsed[0]) == 0)
		{
			return (func_arr[i].f);
		}
	}
	return (NULL);
}

