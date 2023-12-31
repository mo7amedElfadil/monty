#include "monty.h"
/**
 * _nop - does nothing
 * @stack: stack head
 * @line_number: line number
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack, (void)line_number;
}
/**
 * _pchar - pchar/ print char operation for stack
 * @stack: stack head
 * @line_number: line number
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n", line_number);
		free_mode(), free(mode.opcodes);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n >= 0 && (*stack)->n <= 127)
		dprintf(STDOUT_FILENO, "%c\n", (*stack)->n);
	else
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range\n",
				line_number);
		free_mode(), free(mode.opcodes);
		exit(EXIT_FAILURE);
	}
}
/**
 * _pstr - pstr/ print string operation for stack
 * @stack: stack head
 * @line_number: line number
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (!stack || !*stack || !(*stack)->n)
	{
		dprintf(STDOUT_FILENO, "\n");
		return;
	}
	if ((*stack)->n > 0 && (*stack)->n <= 127)
	{
		dprintf(STDOUT_FILENO, "%c", (*stack)->n);
		_pstr(&(*stack)->next, line_number);
	}
	else
		dprintf(STDOUT_FILENO, "\n");
}

/**
 * _rotl - rotates the stack to the top.
 * * @stack: stack head
 * @line_number: line number
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	int x;
	stack_t *h = *stack;

	(void)line_number;
	if (!h || !h->next)
		return;
	x = (*stack)->n;
	for (; h->next; h = h->next)
		h->n = h->next->n;
	h->n = x;
}
/**
 * _rotr - rotates the stack to the bottom.
 * * @stack: stack head
 * @line_number: line number
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *h = mode.tail;
	int x;

	(void)line_number, (void)stack;
	if (!(*stack) || !(*stack)->next)
		return;
	x = h->n;
	for (; h->prev; h = h->prev)
	{
		h->n = h->prev->n;
	}
	h->n = x;
}

