#include "monty.h"


/**
  * push - pushes an element to the stack.
  * @stack: stack data type
  * @line_number: new value to add to the stack
  */

void push(stack_t **stack, unsigned int line_number)
{
	int n, j;

	if (!glob_var.arg)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	for (j = 0; glob_var.arg[j] != '\0'; j++)
	{
		if (!isdigit(glob_var.arg[j]) && glob_var.arg[j] != '-')
		{
			fprintf(stderr, "L%u: ", line_number);
			fprintf(stderr, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(glob_var.arg);

	if (glob_var.data_type == 1)
		add_dnodeint(stack, n);
	else
		add_dnodeint_end(stack, n);
}
