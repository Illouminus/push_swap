/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaillot <ebaillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:18:12 by edouard           #+#    #+#             */
/*   Updated: 2024/02/15 14:55:51 by ebaillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Converts a string to a long integer.
 * @param s The string to convert.
 * @return The long integer representation of the string.
 */
static long ft_atol(const char *s)
{
	long result = 0;
	int sign = 1;

	while (*s == ' ' || *s == '\t' || *s == '\n' ||
			 *s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return result * sign;
}

/**
 * Appends a new node with value 'n' to the end of a stack.
 * @param stack The stack to append to.
 * @param n The value to be added.
 */
static void append_node(t_stack_node **stack, int n)
{
	if (!stack)
		return;

	t_stack_node *node = malloc(sizeof(t_stack_node));
	if (!node)
		return;

	node->next = NULL;
	node->nbr = n;

	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		t_stack_node *last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

/**
 * Initializes stack 'a' with values from argv, handling errors and duplicates.
 * @param a The stack to initialize.
 * @param argv The values to add to the stack.
 */
void init_stack_a(t_stack_node **a, char **argv)
{
	long n;
	int i = 0;

	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (error_duplicate(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n);
		i++;
	}
}

/**
 * Finds and returns the cheapest node in a stack.
 * @param stack The stack to search in.
 * @return Pointer to the cheapest node, or NULL if none found.
 */
t_stack_node *get_cheapest(t_stack_node *stack)
{
	while (stack)
	{
		if (stack->cheapest)
			return stack;
		stack = stack->next;
	}
	return NULL;
}

/**
 * Prepares a stack by moving the specified node to the top.
 * @param stack The stack to modify.
 * @param top_node The node to move to the top of the stack.
 * @param stack_name The name of the stack ('a' or 'b').
 */
void prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
