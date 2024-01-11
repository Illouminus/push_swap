/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:28:22 by edouard           #+#    #+#             */
/*   Updated: 2024/01/11 22:29:41 by edouard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

void move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack *cheapest_node;

	cheapest_node = find_cheapest(*a);
	if (cheapest_node->is_median && cheapest_node->target_node->is_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->is_median) && !(cheapest_node->target_node->is_median))
		rev_rotate_both(a, b, cheapest_node);
	ready_push(a, cheapest_node, 'a');
	ready_push(b, cheapest_node->target_node, 'b');
	pb(b, a, false);
}

void move_b_to_a(t_stack **a, t_stack **b)
{
	ready_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}