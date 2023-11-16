#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * _open_monty - open a monty file.m
 * @f_name: name of file
 * Return: file stream
 */
FILE *_open_monty(char *f_name)
{
	FILE *stream;


	stream = fopen(f_name, "r");
	if (!stream || _check_monty_file(f_name))
	{
		char *err_msg = _file_error("Error: Can't open file ", f_name);

		_put_error(err_msg), free(err_msg);
		if (stream)
			fclose(stream);
		exit(EXIT_FAILURE);
	}
	else
		return (stream);
}

/**
 * _tokenize_opcodes - tokenize the input line for opcodes and int.
 * @input: the line/string returned from getline.
 * Return: array of strings (opcodes).
 */
char **_tokenize_opcodes(char *input)
{
	int i = 0;
	char *token, **opcodes;

	token =  strtok(input, " \t\r\n\v\f");
	if (!token)
	{	return (NULL); }
	mode.n_op = num_of_ops(token);
	opcodes = malloc(sizeof(*opcodes) * (mode.n_op + 1));
	if (!opcodes)
		_put_error("Error: malloc failed\n"), exit(EXIT_FAILURE);
	opcodes[i] = malloc(_strlen(token) + 1);
	if (!*opcodes)
		_put_error("Error: malloc failed\n"), exit(EXIT_FAILURE);
	_strcpy(opcodes[i], token);
	while (opcodes[i] && i < mode.n_op - 1)
	{
		i++, token = strtok(NULL, " \t\r\n\v\f");
		if (!token)
		{
			break; }
		opcodes[i] = malloc(_strlen(token) + 1);
		if (!opcodes[i])
			_put_error("Error: malloc failed\n"), exit(EXIT_FAILURE);
		_strcpy(opcodes[i], token);
	} opcodes[mode.n_op] = NULL;
	return (opcodes);
}
/**
 * _check_monty_file - checks if file is a monty.m file
 * @f_name: file name
 * Return: 0 if it is a monty.m file, 1 otherwise.
 */
int _check_monty_file(char *f_name)
{
	int len = _strlen(f_name);

	return (f_name[len - 1] != 'm' || f_name[len - 2] != '.');
}
