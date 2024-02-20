/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaillot <ebaillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:03:33 by edouard           #+#    #+#             */
/*   Updated: 2024/02/20 14:23:50 by ebaillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Checks for syntax errors in the input string representing a number.
 * Returns 1 for an error, 0 otherwise.
 * @param str_n The input string to check.
 * @return int 1 if there's a syntax error, 0 otherwise.
 */
int	error_syntax(char *str_n)
{
	if (!(*str_n == '+' || *str_n == '-' || (*str_n >= '0' && *str_n <= '9')))
		return (1);
	if ((*str_n == '+' || *str_n == '-') && !(str_n[1] >= '0'
			&& str_n[1] <= '9'))
		return (1);
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);
}

/**
 * Checks for duplicate numbers in the stack.
 * Returns 1 if a duplicate is found, 0 otherwise.
 * @param a The stack to check.
 * @param n The number to check for duplicates.
 * @return int 1 if a duplicate is found, 0 otherwise.
 */
int	error_duplicate(t_stack_node *a, int n)
{
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

/**
 * Frees all nodes in a stack.
 * @param stack The stack to be freed.
 */
void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

/**
 * Frees the stack and prints an
 * error message upon encountering a unique error.
 * @param a The stack to be freed.
 */
void	free_errors(t_stack_node **a)
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}
