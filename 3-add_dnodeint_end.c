#include "monty.h"

/**
  * add_dnodeint_end -  adds a new node at the end of a stack_t list.
  * @head: head of the list
  * @n: new node data
  * Return: the address of the new element, or NULL if it failed
  */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new_node, *temp;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL || head == NULL)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	temp = *head;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = new_node;
	new_node->prev = temp;
	return (new_node);
}

