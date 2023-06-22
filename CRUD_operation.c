#include "monty.h"
#include "lists.h"

/**
 * pint_handler - handles the pint instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void pint_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (!head)
		error_pint(line_number);
	printf("%d\n", head->n);
}

/**
 * pop_handler - handles the pop instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void pop_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!temp)
		error_pop(line_number);
	delete_dnodeint_at_index(stack, 0);
}

/**
 * add_handler - handles the add instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void add_handler(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_dnodeint_at_index(*stack, 0);
	stack_t *node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, ADD_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}
	sum = node_0->n + node_1->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint(stack, sum);
	if (!node)
		malloc_fail();
}

/**
 * push_handler - handles the push instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void push_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int num = 0, i;

	if (data.words[1] == NULL)
		error_push(line_number);

	for (i = 0; data.words[1][i]; i++)
	{
		if (isalpha(data.words[1][i]) != 0)
			error_push(line_number);
	}
	num = atoi(data.words[1]);

	if (data.qflag == 0)
		new = add_dnodeint(stack, num);
	else if (data.qflag == 1)
		new = add_dnodeint_end(stack, num);
	if (!new)
		malloc_fail();
}

/**
 * pall_handler - handles the pall instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void pall_handler(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack)
		print_dlistint(*stack);
}

