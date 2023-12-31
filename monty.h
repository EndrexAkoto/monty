#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"


/* GLOBAL OPCODE TOKEN */
extern char **op_toks;


/**
 * struct stack_s - doubly linked list representation for stack
 * @n: integer
 * @prev: points previous element of stack
 * @next: points next element of stack
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode  its function
 * @opcode: opcode
 * @f: handles opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO  project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* PRIMARY INTERPRETER FUNCTIONS */
void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);
void free_tokens(void);
unsigned int token_arr_len(void);
int run_monty(FILE *script_fd);
void set_op_tok_error(int error_code);


/* OPCODE FUNCTIONS */
void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);
void monty_add(stack_t **stack, unsigned int line_number);
void monty_nop(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);
void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);


/* CUSTOM STANDARD LIBRARY FUNCTION */
char **strtow(char *str, char *delims);
char *get_int(int n);


/* ERROR MESSAGES & ERROR CODE */
int malloc_error(void);
int usage_error(void);
int unknown_op_error(char *opcode, unsigned int line_number);
int f_open_error(char *filename);
int pop_error(unsigned int line_number);
int no_int_error(unsigned int line_number);
int short_stack_error(unsigned int line_number, char *op);
int pint_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);
int div_error(unsigned int line_number);

char **op_toks;

#endif

