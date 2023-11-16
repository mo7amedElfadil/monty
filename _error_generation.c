#include "monty.h"
/**
 * _file_error - generate file error message
 * @msg: message to concat
 * @f_name: file name
 * Return: error message
 */
char *_file_error(char *msg, char *f_name)
{
	char *err_msg = malloc(BUFF);

	_strcpy(err_msg, msg);
	if (f_name)
		_strcat(err_msg, f_name);
	_strcat(err_msg, "\n");
	return (err_msg);
}
/**
 * _generate_choose_op_err - generate operation choice error message
 * @line_number: line number
 * @cmd: incorrect opcode
 * Return: error message
 */
char *_generate_choose_op_err(int line_number, char *cmd)
{
	char *err_msg = malloc(BUFF), *at;

	at = _itoa(line_number);
	_strcpy(err_msg, "L");
	_strcat(err_msg, at), free(at);
	_strcat(err_msg, ": unknown instruction ");
	_strcat(err_msg, cmd);
	_strcat(err_msg, "\n");
	return (err_msg);
}
/**
 * op_usage_err - generate operation usage error message
 * @opcodes: correct opcode, incorrect int type
 * @line_number: line number
 * Return: error message
 */

char *op_usage_err(char *opcodes, int line_number)
{
	char *err_msg = malloc(BUFF), *at;

	at = _itoa(line_number);
	_strcpy(err_msg, "L");
	_strcat(err_msg, at), free(at);
	_strcat(err_msg, ": usage: ");
	_strcat(err_msg, opcodes);
	_strcat(err_msg, " integer\n");
	return (err_msg);
}
/**
 * _p_err - generate custom error message
 * @line_number: line number
 * @msg: message to concat
 * Return: error message
 */
char *_p_err(int line_number, char *msg)
{
	char *err_msg = malloc(BUFF), *at;

	at = _itoa(line_number);
	_strcpy(err_msg, "L");
	_strcat(err_msg, at), free(at);
	_strcat(err_msg, msg);
	return (err_msg);


}

