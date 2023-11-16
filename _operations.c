#include "monty.h"
/**
 * _choose_op - takes in opcode (cmd) and chooses the function to execute
 * @cmd: opcodes
 * @line_number: line number of file starting with 1
 */

void _choose_op(char *cmd, int line_number)
{
	instruction_t ins[] = {{"push", _push}, {"pall", _pall},
		{"pint", _pint}, {"pop", _pop}, {"swap", _swap},
		{"add", _add}, {"nop", _nop}, {"sub", _sub}, {"div", _div},
		{"mul", _mul}, {"mod", _mod}, {"pchar", _pchar}, {"pstr", _pstr},
		{"rotl", _rotl}, {"rotr", _rotr},
		{0, 0}};
	int i = 0;

	for (i = 0; ins[i].opcode; i++)
	{
		if (!strcmp(cmd, ins[i].opcode))
		{
			ins[i].f(&(mode.head), line_number);
			return;
		}
	}
	dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line_number, cmd);
	free_mode(), free(mode.opcodes);
	exit(EXIT_FAILURE);

}
/**
 * _mode_choice - takes in opcode (cmd) and decides on the mode of operation
 * i.e. stack / queue
 * @cmd: opcodes
 * Return: stack 0, queue 1
 */
int _mode_choice(char *cmd)
{
	if (!_strcmp(cmd, "stack"))
	{
		mode.mode = 0;
		return (1);
	}
	else if (!_strcmp(cmd, "queue"))
	{
		mode.mode = 1;
		return (1);
	}
	else
		return (0);
}
/**
 * num_of_ops - takes in opcode (cmd) and determines number of allocations
 * @first_op: first opcodes
 * Return: 2 or 1
 */
int num_of_ops(char *first_op)
{
	n_ops ops[] = {{"push", 2},	{0, 1}};
	int i = 0;

	for (i = 0; ops[i].opcode; i++)
	{
		if (!strcmp(first_op, ops[i].opcode))
		{
			return (ops[i].n);
		}
	}
	return (1);

}
