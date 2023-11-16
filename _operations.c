#include "monty.h"
/**
 * assign_op - takes in opcodes and modifies the mode
 * @opcodes: opcodes
 * @line_number: line number of file starting with 1
 */
void assign_op(char **opcodes, int line_number)
{
	mode.mode = _mode_choice(*opcodes);
	if (opcodes[1] && _strcmp(*opcodes, "pall"))
	{
		if (!_isnumeric(opcodes[1]))
			mode.n = _atoi(opcodes[1]);
		else
		{
			char *err_msg = op_usage_err(*opcodes, line_number);

			_put_error(err_msg), free(err_msg);
			free_mode(), free_opcodes(mode.opcodes);
			exit(EXIT_FAILURE);
		}
	}
}
/**
 * _choose_op - takes in opcode (cmd) and chooses the function to execute
 * @cmd: opcodes
 * @line_number: line number of file starting with 1
 */

void _choose_op(char *cmd, int line_number)
{
	instruction_t ins[] = {{"push", _push}, {"pall", _pall},
		{"pint", _pint}, {"pop", _pop}, {"swap", _swap},
		{"add", _add}, {"nop", _nop},
		{0, 0}};
	int i = 0;
	char *err_msg;

	for (i = 0; ins[i].opcode; i++)
	{
		if (!strcmp(cmd, ins[i].opcode))
		{
			ins[i].f(&(mode.head), line_number);
			return;
		}

	}
	err_msg = _generate_choose_op_err(line_number, cmd);
	_put_error(err_msg), free(err_msg);
	free_mode(), free_opcodes(mode.opcodes);
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
		return (0);
	else if (!_strcmp(cmd, "queue"))
		return (1);
	else
		return (mode.mode);
}
/**
 * num_of_ops - takes in opcode (cmd) and determines number of allocations
 * @first_op: first opcodes
 * Return: 2 or 1
 */
int num_of_ops(char *first_op)
{
	n_ops ops[] = {{"push", 2}, {"pall", 1},
		{"pint", 1}, {"pop", 1}, {"swap", 1},
		{"add", 1}, {"nop", 1},
		{0, 1}};
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
