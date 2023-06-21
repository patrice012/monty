#include "monty.h"


/**
  * push - pushes an element to the stack.
  * @stack: stack data type
  * @line_number: new value to add to the stack
  */

void push(stack_t **stack, UNUSED unsigned int line_number)
{
	int n;

	if (!glob_var.arg)
		error_push_value();

	if (!is_numeric(glob_var.arg))
		error_push_value();

	n = atoi(glob_var.arg);

	if (glob_var.data_type == STACK)
		add_dnodeint(stack, n);
	else
		add_dnodeint_end(stack, n);
}
