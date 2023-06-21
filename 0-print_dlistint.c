#include "monty.h"


/**
  * print_dlistint - print list elements
  * @h: list head
  * Return: number of nodes
  */

size_t print_dlistint(const stack_t *h)
{
	int count = 0;
	const stack_t *temp = h;
;
	while (temp)
	{
		count++;
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	return (count);
}
