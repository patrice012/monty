#include "monty.h"
#include "lists.h"

/**
 * sub_handler - handles the sub instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void sub_handler(stack_t **stack, unsigned int line_number)
{
	int sub = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_dnodeint_at_index(*stack, 0);
	stack_t *node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
		error_sub_fail(line_number);

	sub = node_1->n - node_0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint(stack, sub);
	if (!node)
		malloc_fail();
}

/**
 * div_handler - handles the div instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void div_handler(stack_t **stack, unsigned int line_number)
{
	int div = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_dnodeint_at_index(*stack, 0);
	stack_t *node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
		error_div_fail(line_number);

	if (node_0->n == 0)
		error_zero_division(line_number);

	div = node_1->n / node_0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint(stack, div);
	if (!node)
		swap_fail(line_number);
}

/**
 * mul_handler - handles the mul instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void mul_handler(stack_t **stack, unsigned int line_number)
{
	int mul = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_dnodeint_at_index(*stack, 0);
	stack_t *node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
		error_mul_fail(line_number);
	mul = node_1->n * node_0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint(stack, mul);
	if (!node)
		swap_fail(line_number);
}

/**
 * mod_handler - handles the mod instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void mod_handler(stack_t **stack, unsigned int line_number)
{
	int mod = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_dnodeint_at_index(*stack, 0);
	stack_t *node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
		error_mod_fail(line_number);

	if (node_0->n == 0)
		error_zero_division(line_number);

	mod = node_1->n % node_0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint(stack, mod);
	if (!node)
		swap_fail(line_number);
}
