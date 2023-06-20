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
	int len, i;

	instruction_t func[] = {
		{"push", push},
	};

	len = get_len(sizeof(func), func[0]);
	for (i = 0; i < len && func[i].opcode; i++)
	{
		if (strcmp(func[i].opcode, code) == 0)
			return (func[i].f);
	}
	return (NULL);
}
