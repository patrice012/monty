#include "monty.h"

/**
  * free_dlistint - frees a stack_t list.
  * @head: list head
  */

void free_dlistint(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (temp)
	{
		head  = temp->next;
		free(temp);
		temp = head;
	}
}
