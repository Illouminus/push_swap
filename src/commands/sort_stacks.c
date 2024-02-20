/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaillot <ebaillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:57:58 by edouard           #+#    #+#             */
/*   Updated: 2024/02/20 14:34:58 by ebaillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Rotates both stacks 'a' and 'b' until the cheapest node is on top,
	if it's the most efficient move.
 * @param a Stack 'a' to rotate.
 * @param b Stack 'b' to rotate.
 * @param cheapest_node Node considered for the most efficient move.
 */
static void	rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

/**
 * Reverse rotates both stacks 'a'
 * and 'b' until the cheapest node is on top,
	if it's the most efficient move.
 * @param a Stack 'a' to reverse rotate.
 * @param b Stack 'b' to reverse rotate.
 * @param cheapest_node Node considered for the most efficient move.
 */
static void	rev_rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

/**
 * Prepares and moves the cheapest nodes from stack 'a' to stack 'b'.
 * @param a Source stack 'a'.
 * @param b Destination stack 'b'.
 */
static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!cheapest_node->above_median
		&& !cheapest_node->target_node->above_median)
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a, false);
}

/**
 * Prepares and moves nodes from stack 'b' back to stack 'a'.
 * @param a Destination stack 'a'.
 * @param b Source stack 'b'.
 */
static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

/**
 * Sorts the stacks 'a' and 'b', optimizing moves for efficiency.
 * @param a Stack 'a' to sort.
 * @param b Stack 'b' to sort.
 */
void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
