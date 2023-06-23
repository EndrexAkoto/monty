#include "monty.h"

void monty_sub(stack_t **stack, unsigned int line_number);
void monty_add(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);

/**
 * monty_add - adds top two values of stack_t linked list
 * @stack: pointer to top mode node of stack_t linked list
 * @line_number: current working line number of Monty bytecodes file
 *
 * Description: result is stored in second value node
 *              fromtop and the top value removed
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{

	set_op_tok_error(short_stack_error(line_number, "add"));

}

(*stack)->next->next->n += (*stack)->next->n;
monty_pop(stack, line_number);
}

/**
 * monty_sub - subtracts second value from the top of
 *             stack_t linked list by top value
 * @stack: pointer to top mode node of stack_t linked list
 * @line_number: current working line number of Monty bytecodes file
 *
 * Description: result is stored in second value node
 *              from the top and the top value removed
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
	set_op_tok_error(short_stack_error(line_number, "sub"));

}

(*stack)->next->next->n -= (*stack)->next->n;
monty_pop(stack, line_number);
}

/**
 * monty_div - divides second value from the top of
 *             stack_t linked list by  top value
 * @stack: pointer to top mode node of stack_t linked list
 * @line_number: current working line number of a Monty bytecodes file
 *
 * Description: result is stored in second value node
 *              from the top and the top value removed
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
	set_op_tok_error(short_stack_error(line_number, "div"));

}

	if ((*stack)->next->n == 0)
{
	set_op_tok_error(div_error(line_number));

}

(*stack)->next->next->n /= (*stack)->next->n;
monty_pop(stack, line_number);
}

/**
 * monty_mul - multiplies  second value from top of
 *             stack_t linked list by the top value
 * @stack: pointer to  top mode node of stack_t linked list
 * @line_number: current working line number of a Monty bytecodes file
 *
 * Description: result is stored in the second value node
 *              from the top and the top value is removed
 *
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
	set_op_tok_error(short_stack_error(line_number, "mul"));

}

(*stack)->next->next->n *= (*stack)->next->n;
monty_pop(stack, line_number);
}

/**
 * monty_mod - computes  modulus of second value from
 *	top of stack_t linked list  by top value
 * @stack: pointer to top mode node of a stack_t linked list
 * @line_number: current working line number of Monty bytecodes file
 *
 * Description: result is stored in the second value node
 *              from the top and the top value removed
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
	set_op_tok_error(short_stack_error(line_number, "mod"));

}

if ((*stack)->next->n == 0)
{
	set_op_tok_error(div_error(line_number));

}

(*stack)->next->next->n %= (*stack)->next->n;
monty_pop(stack, line_number);
}

