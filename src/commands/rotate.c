/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:53:37 by edouard           #+#    #+#             */
/*   Updated: 2024/01/17 16:28:40 by edouard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Rotates a stack by moving the top node to the bottom.
 * @param stack The stack to perform the rotation on.
 */
static void rotate(t_stack_node **stack)
{
	t_stack_node *last_node;

	// Return if the stack is empty or has only one node
	if (!*stack || !(*stack)->next)
		return;

	// Move the top node to the bottom of the stack
	last_node = find_last(*stack);
	last_node->next = *stack;			  // Set the last node to point to the top node
	*stack = (*stack)->next;			  // Update the top node to the second node
	(*stack)->prev = NULL;				  // Detach the new top node from its predecessor
	last_node->next->prev = last_node; // Link the former top node to the last node
	last_node->next->next = NULL;		  // Set the former top node as the new last node
}

/**
 * Performs the 'ra' operation: rotates the top node of stack 'a' to the bottom.
 * Optionally prints the operation.
 * @param a Pointer to the top of stack 'a'.
 * @param print Flag to print the operation.
 */
void ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}

/**
 * Performs the 'rb' operation: rotates the top node of stack 'b' to the bottom.
 * Optionally prints the operation.
 * @param b Pointer to the top of stack 'b'.
 * @param print Flag to print the operation.
 */
void rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (!print)
		ft_printf("rb\n");
}

/**
 * Performs the 'rr' operation: simultaneously rotates the top nodes of both stacks 'a' and 'b' to the bottom.
 * Optionally prints the operation.
 * @param a Pointer to the top of stack 'a'.
 * @param b Pointer to the top of stack 'b'.
 * @param print Flag to print the operation.
 */
void rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}
