#include "monty.h"
/**
 * _add - add operation for stack
 * @stack: stack head
 * @line_number: line number
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		char *err_msg = _p_err(line_number, ": can't add, stack too short\n");

		_put_error(err_msg), free(err_msg);
		free_mode(), free_opcodes(mode.opcodes);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	_pop(stack, line_number);
}


void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack, (void)line_number;
	return;
}
