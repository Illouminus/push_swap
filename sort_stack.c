/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:24:41 by edouard           #+#    #+#             */
/*   Updated: 2024/01/11 22:43:15 by edouard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sort the stacks, pushing unsorted elements from stack 'a' to 'b' and then sorting them.
void sort_stack(t_stack **a, t_stack **b)
{

	int len_a;

	len_a = stack_len(*a);
	// Push elements from 'a' to 'b' and sort 'a' if it has more than 3 elements and is not sorted.
	while (len_a-- > 3 && !stack_is_sorted(*a))
	{
		pb(b, a, false);
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	// Sort the top three elements in 'a'.
	sort_three(a);
	// Move elements back from 'b' to 'a' and sort them.
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	// Re-index 'a' and ensure smallest element is on top.
	current_index(*a);
	min_on_top(a);
}

// Calculate the cost of moving each node from stack 'a' to the correct position in stack 'b'.
void cost_move(t_stack *a, t_stack *b)
{
	int len_a;
	int len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);

	while (a)
	{
		a->push_cost = a->index; // Set push_cost to the current index of the node in stack a
		if (!(a->is_median))
			a->push_cost = len_a - (a->index);		// Adjust push_cost based on its position relative to the end of the stack
		if (a->target_node->is_median)				// If the target node in stack b is at or above the median
			a->push_cost += a->target_node->index; // Add the index of the target node to push_cost
		else
			a->push_cost += len_b - (a->target_node->index); // If target node is below median, adjust push_cost accordingly
		a = a->next;													 // Move to the next node in stack a
	}
}

// Set the 'cheapest' flag for the node in 'a' with the lowest cost to move.
void set_cheapest(t_stack *a)
{
	long cheapest_cost;
	t_stack *cheapest_node;

	if (!a)
		return;
	cheapest_cost = LONG_MAX;
	while (a)
	{
		if (a->push_cost < cheapest_cost)
		{
			cheapest_cost = a->push_cost;
			cheapest_node = a;
		}
		a = a->next;
	}
	cheapest_node->cheapest = true;
}

static void min_on_top(t_stack **a)
{
	while ((*a)->value != find_min(*a)->value)
	{
		if (find_min(*a)->is_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

// Initialize the nodes in stack 'a' and 'b' for sorting.
void init_nodes_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_move(a, b);
	set_cheapest(a);
}