#include "monty.h"
/**
 * print_stack_t - print a doubly linked list
 * @h: head of doubly linked list
 * Return: size of list
 */
size_t print_stack_t(const stack_t *h)
{
	if (!h)
		return (0);
	printf("%d\n", h->n);

	return (1 + print_stack_t(h->next));
}
/**
 * stack_t_len - finds the len doubly linked list
 * @h: head of doubly linked list
 * Return: len of list
 */
size_t stack_t_len(const stack_t *h)
{
	if (!h)
		return (0);
	return (1 + stack_t_len(h->next));
}

/**
 * add_dnodeint - adds a node at the beginning of a doubly linked list
 * @head: ptr to head ptr of the linked list
 * @n: integer value to be assigned to node
 * Return:  address of a new element or null if failed
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		_put_error("Error: malloc failed\n"), free_mode();
		free(mode.opcodes);
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = *head;
	if (*head)
		(*head)->prev = new;
	new->prev = NULL;
	*head = new;
	return (*head);
}
/**
 * add_dnodeint_end - adds a node at the end of a doubly linked list
 * @head: ptr to head ptr of the linked list
 * @n: integer to be assigned to the new node
 * Return: address of a new element or null if failed
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new = NULL;

	if ((*head) && ((*head)->next))
	{
		return (add_dnodeint_end(&(*head)->next, n));
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		_put_error("Error: malloc failed\n"), free_mode();
		free(mode.opcodes);
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	if (*head)
	{
		new->prev = *head;
		(*head)->next = new;
	}
	else
	{
		new->prev = NULL;
		*head = new;
	}
	return (new);
}
/**
 * delete_dnodeint_at_index - deletes a node at the idx position
 *						of a listint_t linked list.
 * @head: head of the linked list to be printed
 * @index: index of list
 * Return: node at index or NULL if failed
 */

int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	if (!head || !*head)
		return (-1);

	if (index)
	{
		if ((*head)->next)
			return (delete_dnodeint_at_index(&(*head)->next, index - 1));
		else
			return (-1);
	}
	else
	{
		stack_t *temp = *head;

		if (!temp->next && !temp->prev)
		{
			*head = 0;
		}
		else if (!temp->prev)
		{
			(*head) = (*head)->next;
			(*head)->prev = 0;
		}
		else if (!temp->next)
		{
			(*head) = temp->prev;
			(*head)->next = 0;
		}
		else
		{
			(*head) = (*head)->next;
			(*head)->prev = temp->prev;
			temp->prev->next = (*head);
		}
		free(temp);
		return (1);
	}
}
