#include "monty.h"

/**
 * free_stack_t - frees a doubly linked list list_t
 * @head: head of the doubly linked list
 */
void free_stack_t(stack_t *head)
{
	if (head)
	{
		(free_stack_t(head->next));
		free(head);
	}

}
/**
 * free_mode - free the struct mode global variable's allocated members
 * and closes the file
 */
void free_mode(void)
{
	if (mode.stream)
		fclose(mode.stream);
	if (mode.input)
		free(mode.input);
	if (mode.head)
		free_stack_t(mode.head);
	}
