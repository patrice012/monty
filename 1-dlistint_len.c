#include "monty.h"


/**
  * dlistint_len - print list elements
  * @h: list head
  * Return: number of nodes
  */

size_t dlistint_len(const stack_t *h)
{
	int count = 0;
	const stack_t *temp = h;

	if (temp == NULL)
		return (0);
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
