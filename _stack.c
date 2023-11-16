#include "monty.h"
#include <stdio.h>
#include <unistd.h>
/**
 * _push - push operation for stack
 * @stack: stack head
 * @line_number: line number
 */
void _push(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (!mode.mode)
		add_dnodeint(stack, mode.n);
	else
		add_dnodeint_end(stack, mode.n);
}
/**
 * _pall - pall or print all operation for stack
 * @stack: stack head
 * @line_number: line number
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	print_stack_t(*stack);
}

/**
 * _pint - pint/ print int operation for stack
 * @stack: stack head
 * @line_number: line number
 */
void _pint(stack_t **stack, unsigned int line_number)
{

	if (!stack || !*stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		free_mode(), free(mode.opcodes);
		exit(EXIT_FAILURE);
	}
	dprintf(STDOUT_FILENO, "%d\n", (*stack)->n);
}
/**
 * _pop - pop operation for stack
 * @stack: stack head
 * @line_number: line number
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		free_mode(), free(mode.opcodes);
		exit(EXIT_FAILURE);
	}
	else
	{
		delete_dnodeint_at_index(stack, 0);
	}
}
/**
 * _swap - swap operation for stack
 * @stack: stack head
 * @line_number: line number
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		free_mode(), free(mode.opcodes);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->n ^ (*stack)->next->n;
	(*stack)->next->n = (*stack)->n ^ (*stack)->next->n;
	(*stack)->n = (*stack)->n ^ (*stack)->next->n;
}

