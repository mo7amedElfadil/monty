#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L
/* library includes */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdarg.h>
#ifndef BUFF
#define BUFF 120
#endif
/* ****_____ structures _____**** */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct mode_s - doubly linked list mode (stack or queue)
 * @mode: stack (0) , queue (1)
 * @n: integer
 * @n_op: number of allocations for op
 * @stream: pointer to file stream
 * @input: pointer to input line
 * @opcodes: pointer to array opcodes
 * @head: points to the first element of the Data Structure (DS)
 * @tail: points to the last element of the DS
 *
 * Description: doubly linked list mode for the
 * stack, queues, LIFO, FIFO
 */
typedef struct mode_s
{
	int mode;
	int n;
	int n_op;
	FILE *stream;
	char *input;
	char *opcodes;
	struct stack_s *head;
	struct stack_s *tail;
} mode_x;

/* ****_____ globals _____**** */
extern mode_x mode;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct n_ops - opcode and number of allocations
 * @opcode: the opcode
 * @n: number of allocations
 * Description: opcode and number of allocs for opcodes
 */
typedef struct n_ops
{
	char *opcode;
	int n;
} n_ops;


/* ****_____ prototypes _____**** */

/* ****___ _put_buffer.c ___**** */
int _put_buffer(char *c);
int _put_error(char *c);



/* ****___ _error_generation.c ___**** */
char *_file_error(char *msg, char *f_name);
char *_generate_choose_op_err(int line_number, char *cmd);
char *op_usage_err(char *opcodes, int line_number);
char *_p_err(int line_number, char *msg);

/* ****___ _str.c ___**** */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);

/* ****___ _file_manipulation.c ___**** */
FILE *_open_monty(char *f_name);
char *_tokenize_opcodes(char *input, int line_number);
int _check_monty_file(char *f_name);
void assign_num(char *opcodes, char *token, int line_number);

/* ****___ _stack.c ___**** */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
/* ****___ _stack2.c ___**** */
void _add(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);



/* ****___ _linked_list.c ___**** */
size_t print_stack_t(const stack_t *h);
size_t stack_t_len(const stack_t *h);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_stack_t(stack_t *head);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);

/* ****___ _freedom.c ___**** */
void free_mode(void);


/* ****___ _atoi.c ___**** */
int _atoi(char *s);
char *_itoa(int x);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _isnumeric(char *c);
void _rev_string(char *s);





/* ****___ _operations.c ___**** */
void assign_op(char *opcodes);
int _mode_choice(char *cmd);
void _choose_op(char *cmd, int line_number);
int num_of_ops(char *first_op);

#endif
