#include "monty.h"
#include "lists.h"





/**
 * swap_handler - handles the swap instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void swap_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *node = NULL;
	int num;

	if (dlistint_len(*stack) < 2)
		swap_fail(line_number);

	temp = get_dnodeint_at_index(*stack, 0);
	num = temp->n;
	delete_dnodeint_at_index(stack, 0);
	node = insert_dnodeint_at_index(stack, 1, num);
	if (!node)
		malloc_fail();
}



/**
 * nop_handler - handles the nop instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void nop_handler(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
