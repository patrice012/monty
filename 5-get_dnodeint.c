#include "monty.h"

/**
  * get_dnodeint_at_index - get  nth node of a stack_t linked list.
  * @head: head of the list
  * @index: index of the element to get
  * Return: the node or  NULL if node does not exist
  */

stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index)
{
	unsigned int count = 0;
	stack_t *temp = head;

	if (head == NULL)
		return (NULL);

	while (temp)
	{
		if (index == count)
			return (temp);
		temp = temp->next;
		count++;
	}
	return (NULL);
}
