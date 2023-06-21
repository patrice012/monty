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




/**
  * add_dnodeint - add node at the beginning
  * @head: head of the list
  * @n: new node data
  * Return: the address of the new element, or NULL if it failed
  */

stack_t *add_dnodeint(stack_t **head, const int n)
{
    stack_t *new_node;

    new_node = malloc(sizeof(stack_t));

    if (new_node == NULL || head == NULL)
        return (NULL);
    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *head;
    *head = new_node;
    if (new_node->next)
        new_node->next->prev = new_node;
    return (new_node);
}


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
