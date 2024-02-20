/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaillot <ebaillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:51:08 by edouard           #+#    #+#             */
/*   Updated: 2024/02/20 14:28:02 by ebaillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Rotates a stack by moving the bottom node to the top.
 * @param stack The stack to perform the reverse rotation on.
 */

static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
}

/**
 * Performs the 'rra' operation:
 * reverse rotates the stack 'a'.
 * Optionally prints the operation.
 * @param a Pointer to the top of stack 'a'.
 * @param print Flag to print the operation.
 */
void	rra(t_stack_node **a, bool print)
{
	rev_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

/**
 * Performs the 'rrb' operation:
 * reverse rotates the stack 'b'.
 * Optionally prints the operation.
 * @param b Pointer to the top of stack 'b'.
 * @param print Flag to print the operation.
 */
void	rrb(t_stack_node **b, bool print)
{
	rev_rotate(b);
	if (!print)
		ft_printf("rrb\n");
}

/**

	* Performs the 'rrr' operation:
	simultaneously reverse rotates both stacks 'a' and 'b'.
 * Optionally prints the operation.
 * @param a Pointer to the top of stack 'a'.
 * @param b Pointer to the top of stack 'b'.
 * @param print Flag to print the operation.
 */
void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!print)
		ft_printf("rrr\n");
}
