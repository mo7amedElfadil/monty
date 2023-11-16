#include "monty.h"

/**
 * free_opcodes - frees all opcode buffs
 * @cmds: array of tokens/commands
 */
void free_opcodes(char **cmds)
{
	int idx = 0;

	if (cmds)
	{
		while (cmds[idx])
		{
			free(cmds[idx]);
			idx++;
		}
	}
	if (cmds)
	{
		free(cmds);
		cmds = 0;
	}
}
/**
 * free_vars - free the all the allocated memory for exit.
 * @n:number of arguments .
 * Return: void.
 */

void free_vars(int n, ...)
{
	va_list ap;

	va_start(ap, n);
	for (; n > 0; n--)
	{
		void *ptr = va_arg(ap, void *);

		if (ptr)
		{
			free(ptr);
		}
	}
	va_end(ap);
}
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
