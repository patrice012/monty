#include "monty.h"

/**
 * math_operations - calculates using the OPCODE of the top two
 * elements of the stack
 *
 * @opcode: opcode to be executed
 *
 * Return: 0 on success, -1 on failure
 */
int math_operations(char *opcode)
{
	int result = 0;

	if (list_head == NULL || list_head->next == NULL)
	{
		error_short_stack(opcode);
		return (-1);
	}

	if (_strcmp(opcode, "add") == 0)
		result = list_head->n + list_head->next->n;
	else if (_strcmp(opcode, "sub") == 0)
		result = list_head->next->n - list_head->n;
	else if (_strcmp(opcode, "div") == 0)
	{
		if (list_head->n == 0)
		{
			error_div_zero();
			return (-1);
		}
		result = list_head->next->n / list_head->n;
	}
	else if (_strcmp(opcode, "mul") == 0)
		result = list_head->n * list_head->next->n;
	else if (_strcmp(opcode, "mod") == 0)
	{
		if (list_head->n == 0)
		{
			error_div_zero();
			return (-1);
		}
		result = list_head->next->n % list_head->n;
	}

	pop_front();
	pop_front();
	push_front(result);

	return (0);
}

/**
 * op_pchar - prints the char at the top of the stack
 *
 * Return: 0 on success, -1 on failure
 */
int op_pchar(void)
{
	char *c;

	if (list_head == NULL)
	{
		error_short_stack("pchar");
		return (-1);
	}

	if (list_head->n < 0 || list_head->n > 127)
	{
		error_pchar();
		return (-1);
	}

	c = malloc(sizeof(char) * 3);
	c[0] = list_head->n;
	c[1] = '\n';
	c[2] = '\0';

	print_str(c);

	free(c);
	return (0);
}

/**
 * op_pstr - prints the string starting at the top of the stack
 *
 * Return: 0 on success, -1 on failure
 */
int op_pstr(void)
{
	stack_t *tmp = list_head;
	char *c;

	while (tmp != NULL && tmp->n > 0 && tmp->n <= 127)
	{
		c = malloc(sizeof(char) * 2);
		c[0] = tmp->n;
		c[1] = '\0';

		print_str(c);

		free(c);
		tmp = tmp->next;
	}

	print_str("\n");
	return (0);
}

/**
 * print_operations - preform print operations on the stack
 *
 * @opcode: opcode to be executed
 *
 * Return: 0 on success, -1 on failure
 */
int print_operations(char *opcode)
{
	int rn = 0;

	if (_strcmp(opcode, "pall") == 0)
		rn = op_pall();
	else if (_strcmp(opcode, "pint") == 0)
		rn = op_pint();
	else if (_strcmp(opcode, "pchar") == 0)
		rn = op_pchar();
	else if (_strcmp(opcode, "pstr") == 0)
		rn = op_pstr();

	return (rn);
}

/**
 * rotation_operations - preform rotation operations on the stack
 *
 * @opcode: opcode to be executed
 *
 * Return: 0 on success, -1 on failure
 */
int rotation_operations(char *opcode)
{
	int rn = 0;

	if (_strcmp(opcode, "rotl") == 0)
		rn = op_rotl();
	else if (_strcmp(opcode, "rotr") == 0)
		rn = op_rotr();

	return (rn);
}
