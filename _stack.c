#include "monty.h"
/**
 * _push - push operation for stack
 * @stack: stack head
 * @line_number: line number
 */
void _push(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	add_dnodeint(stack, mode.n);
}
/**
 * _pall - pall or print all operation for stack
 * @stack: stack head
 * @line_number: line number
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	print_stack_t(*stack);
	(void)line_number;
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
		char *err_msg = _p_err(line_number, ": can't pint, stack empty\n");

		_put_error(err_msg), free(err_msg);
		free_mode(), free_opcodes(mode.opcodes);
		exit(EXIT_FAILURE);
	}
	else
	{
		char *i = _itoa((*stack)->n);

		_put_buffer(i), free(i);
		_put_buffer("\n");
	}
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
		char *err_msg = _p_err(line_number, ": can't pop an empty stack\n");

		_put_error(err_msg), free(err_msg);
		free_mode(), free_opcodes(mode.opcodes);
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
		char *err_msg = _p_err(line_number, ": can't swap, stack too short\n");

		_put_error(err_msg), free(err_msg);
		free_mode(), free_opcodes(mode.opcodes);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->n ^ (*stack)->next->n;
	(*stack)->next->n = (*stack)->n ^ (*stack)->next->n;
	(*stack)->n = (*stack)->n ^ (*stack)->next->n;
}

