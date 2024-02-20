/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaillot <ebaillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:53:37 by edouard           #+#    #+#             */
/*   Updated: 2024/02/20 14:28:28 by ebaillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Rotates a stack by moving the top node to the bottom.
 * @param stack The stack to perform the rotation on.
 */
static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

/**
 * Performs the 'ra' operation: rotates
 *  the top node of stack 'a' to the bottom.
 * Optionally prints the operation.
 * @param a Pointer to the top of stack 'a'.
 * @param print Flag to print the operation.
 */
void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}

/**
 * Performs the 'rb' operation: rotates
 * the top node of stack 'b' to the bottom.
 * Optionally prints the operation.
 * @param b Pointer to the top of stack 'b'.
 * @param print Flag to print the operation.
 */
void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (!print)
		ft_printf("rb\n");
}

/**
	* Performs the 'rr' operation: simultaneously
	rotates the top nodes of both stacks 'a' and 'b' to the bottom.
 * Optionally prints the operation.
 * @param a Pointer to the top of stack 'a'.
 * @param b Pointer to the top of stack 'b'.
 * @param print Flag to print the operation.
 */
void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}
