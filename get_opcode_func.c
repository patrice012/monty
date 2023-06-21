#include "monty.h"

/**
  * get_len - get the len of array
  * @arr_size: array size
  * @f: size of opcode function
  * Return: size of array
  */

int get_len(size_t arr_size, instruction_t f)
{
	return (arr_size / sizeof(f));
}

/**
  * get_func - get the opcode function
  * @code: opcode name
  * Return: pointer to function
  */

void (*get_func(char *code))(stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t func[] = {
		{"push", push},
		{"pall", f_pall},
		{"pint", f_pint},
	};

	for (i = 0; func[i].opcode; i++)
	{
		if (strcmp(func[i].opcode, code) == 0)
			return (func[i].f);
	}
	return (NULL);
}
