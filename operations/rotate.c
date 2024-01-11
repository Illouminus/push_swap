/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:55:56 by edouard           #+#    #+#             */
/*   Updated: 2024/01/11 10:13:48 by edouard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_stack(t_stack **stack)
{
	t_stack *last_node;

	if (!(*stack) || !(*stack)->next)
		return;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->next = NULL;
	last_node->next->prev = last_node;
}

void ra(t_stack **a, bool print)
{
	rotate_stack(a);
	if (!print)
		ft_printf("ra\n");
}

void rb(t_stack **b, bool print)
{
	rotate_stack(b);
	if (!print)
		ft_printf("rb\n");
}

void rr(t_stack **a, t_stack **b, bool print)
{
	rotate_stack(a);
	rotate_stack(b);
	if (!print)
		ft_printf("rr\n");
}