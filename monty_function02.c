#include "monty.h"

void monty_nop(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);

/**
 * monty_nop - does absolutely nothing for monty opcode 'nop'
 * @stack: pointer to top mode node of stack_t linked list
 * @line_number: current working line number of a monty bytecodes file
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * monty_pchar - Prints character in  top value
 *               node of stack_t linked list
 * @stack: pointer to the top mode node of stack_t linked list
 * @line_number: current working line number of Monty bytecodes file
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
{
	set_op_tok_error(pchar_error(line_number, "stack empty"));

}

	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
{
	set_op_tok_error(pchar_error(line_number, "value out of range"));

}
printf("%c\n", (*stack)->next->n);
}
/**
 * monty_pstr - prints string contained in a stack_t linked list
 * @stack: pointer to the top mode node of a stack_t linked list
 * @line_number: current working line number of a Monty bytecodes file
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
{
	printf("%c", tmp->n);
	tmp = tmp->next; }
	printf("\n");

	(void)line_number;
}

