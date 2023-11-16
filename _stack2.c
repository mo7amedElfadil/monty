#include "monty.h"
#include <stdlib.h>
/**
 * _add - add operation for stack
 * @stack: stack head
 * @line_number: line number
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{

		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		free_mode(), free(mode.opcodes);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	_pop(stack, line_number);
}
/**
 * _sub - sub operation for stack
 * @stack: stack head
 * @line_number: line number
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", line_number);
		free_mode(), free(mode.opcodes);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	_pop(stack, line_number);
}
/**
 * _div - div operation for stack
 * @stack: stack head
 * @line_number: line number
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", line_number);

		free_mode(), free(mode.opcodes);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n)
	{
		(*stack)->next->n /= (*stack)->n;
		_pop(stack, line_number);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		free_mode(), free(mode.opcodes);
		exit(EXIT_FAILURE);

	}
}
/**
 * _mul - mul operation for stack
 * @stack: stack head
 * @line_number: line number
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{

		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", line_number);

		free_mode(), free(mode.opcodes);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	_pop(stack, line_number);
}
/**
 * _mod - mod operation for stack
 * @stack: stack head
 * @line_number: line number
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", line_number);
		free_mode(), free(mode.opcodes);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n)
	{
		(*stack)->next->n %= (*stack)->n;
		_pop(stack, line_number);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		free_mode(), free(mode.opcodes);
		exit(EXIT_FAILURE);
	}
}

