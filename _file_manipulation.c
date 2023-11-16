#include "monty.h"
#include <stdio.h>
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
	char *token, **opcodes = malloc(sizeof(*opcodes) * 3);

	token =  strtok(input, " \t\r\n\v\f");
	if (!token)
	{	free(opcodes);
		return (NULL); }
	opcodes[i] = malloc(_strlen(token) + 1);
	_strcpy(opcodes[i], token);
		while (opcodes[i] && i < 2)
		{
			i++, token = strtok(NULL, " \t\r\n\v\f");
			if (!token)
			{
				break; }
			opcodes[i] = malloc(_strlen(token) + 1);
			_strcpy(opcodes[i], token);
	} opcodes[i] = NULL;
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
