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
 * @line_number: line number
 * Return: array of strings (opcodes).
 */
char *_tokenize_opcodes(char *input, int line_number)
{
	char *token;

	(void)line_number;
	token =  strtok(input, " \t\r\n\v\f");
	if (!token || *token == '#')
	{	return (NULL); }
	mode.opcodes = malloc(_strlen(token) + 1);
	if (!mode.opcodes)
		_put_error("Error: malloc failed\n"), exit(EXIT_FAILURE);
	_strcpy(mode.opcodes, token);
	token =  strtok(NULL, " \t\r\n\v\f");
	if (token && num_of_ops(mode.opcodes) == 2)
		assign_num(mode.opcodes, token, line_number);
	return (mode.opcodes);
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

/**
 * assign_num - assigns number to be pushed onto the DS
 * @opcodes: instruction to check if it is meant to add a number
 * @token: number
 * @line_number: line number
 */
void assign_num(char *opcodes, char *token, int line_number)
{
	if (token)
	{
		if (!_isnumeric(token))
			mode.n = _atoi(token);
		else
		{
			char *err_msg = op_usage_err(opcodes, line_number);

			_put_error(err_msg), free(err_msg);
			free_mode(), free(mode.opcodes);
			exit(EXIT_FAILURE);
		}
	}
}
