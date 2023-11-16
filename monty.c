#include "monty.h"
#include <stdlib.h>

mode_x mode;
/**
 * main - Entry point
 * @ac: argument count
 * @av: argument vector
 * Return: Always 0 (Success)
 */
int main(int ac, char *av[])
{
	char *f_name;
	size_t len = BUFSIZ;
	int line = 0, line_number = 1;

	mode.mode = 0;
	mode.n = 0;
	mode.n_op = 0;
	mode.opcodes = 0;
	mode.head = NULL;
	mode.tail = NULL;
	if (ac != 2)
	{
		_put_error("USAGE: monty file\n"), exit(EXIT_FAILURE);
	}
	/* file name */
	f_name = av[1];
	/* get file stream to pass to getline */
	mode.stream = _open_monty(f_name);
	mode.input = malloc(len);
	line = getline(&(mode.input), &len, mode.stream);
	while (line >= 0)
	{
		mode.opcodes = _tokenize_opcodes(mode.input);
		if (mode.opcodes)
		{
			assign_op(mode.opcodes, line_number);
			_choose_op(*mode.opcodes, line_number);
			free_opcodes(mode.opcodes);
		}
		line = getline(&(mode.input), &len, mode.stream);
		line_number++;
	}
	free_mode();
	return (0);
}


